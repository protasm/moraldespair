//
// daemon/AI_d.c
//
// Production AI daemon using ERQ/XERQ.
//

#pragma strong_types
#pragma save_types

#include <sys/erq.h>
#include "/daemon/AI_d.h"

#define AI_HOST_IP ({127, 0, 0, 1})
#define AI_PORT 8000
#define AI_PATH "/query"
#define AI_TIMEOUT 45
#define AI_POLL_INTERVAL 10

private mapping requests;
private int next_id;

/* forward declarations */
private void debug_msg(string msg);
private int  start_request(mapping payload, object cb_obj, string cb_func);
private void tcp_open_cb(int *reply, int id);
private void tcp_read_cb(mixed msg, int id);
private void deliver(mapping req);
private void fail(mapping req, string msg);
private void notify(mapping req, string statuz, mixed payload);
private void cleanup(int id);
public  void check_timeouts();
private void kill_request(mapping req);
private void request_read(mapping req, int id);

void create() {
  requests = ([]);
  next_id = 1;
  call_out("check_timeouts", AI_POLL_INTERVAL);
}

private void debug_msg(string msg) {
  object watcher;

  watcher = find_player("solfeggio");
  if (!objectp(watcher))
    return;

  tell_object(watcher, msg);
}

/* =========================================================
 * Public API
 * ========================================================= */

public int query(string prompt, object cb_obj, string cb_func) {
  mapping payload;

  if (!stringp(prompt))
    raise_error("AI_d->query(): prompt must be string\n");

  debug_msg(sprintf("[AI_D] query prompt len=%d cb_obj=%O cb_func=%s\n",
    sizeof(prompt), cb_obj, cb_func));

  payload = ([ "prompt" : prompt ]);

  return start_request(payload, cb_obj, cb_func);
}

public int query_response(
  mixed npc_id,
  mixed player_id,
  string event,
  mapping context,
  mapping options,
  object cb_obj,
  string cb_func
) {
  mapping payload;

  if (!stringp(event))
    raise_error("AI_d->query_response(): event must be string\n");

  if (!mappingp(context))
    raise_error("AI_d->query_response(): context must be mapping\n");

  if (!mappingp(options))
    raise_error("AI_d->query_response(): options must be mapping\n");

  payload = ([
    "npc_id"    : npc_id,
    "player_id" : player_id,
    "event"     : event,
    "context"   : context,
    "options"   : options,
  ]);

  debug_msg(sprintf("[AI_D] query_response event=%s npc=%O player=%O\n",
    event, npc_id, player_id));

  return start_request(payload, cb_obj, cb_func);
}

public mapping req_status() {
  return copy(requests);
}

/* =========================================================
 * Internal request handling
 * ========================================================= */

private int start_request(mapping payload, object cb_obj, string cb_func) {
  int id;
  mapping req;
  int *msg;

  if (!objectp(cb_obj) || !stringp(cb_func))
    raise_error("AI_d->start_request(): bad callback\n");

  id = next_id++;

  req = ([
    "id"         : id,
    "payload"    : payload,
    "cb_obj"     : cb_obj,
    "cb_func"    : cb_func,
    "buffer"     : "",
    "started_at" : time(),
    "updated_at" : time(),
    "got_data"   : 0,
  ]);

  requests[id] = req;

  msg = AI_HOST_IP + ({ AI_PORT / 256, AI_PORT & 255 });

  send_erq(
    ERQ_OPEN_TCP,
    msg,
    lambda(({ 'reply, 'len }), ({ #'tcp_open_cb, 'reply, id }))
  );

  debug_msg(sprintf("[AI_D] request %d stored payload=%O cb_obj=%O cb_func=%s\n",
    id, payload, cb_obj, cb_func));

  return id;
}

/* =========================================================
 * ERQ callbacks
 * ========================================================= */

private void tcp_open_cb(int *reply, int id) {
  mapping req;
  int *ticket;
  string body, http;

  req = requests[id];
  if (!req) {
    debug_msg(sprintf("[AI_D] tcp_open_cb: missing request id=%d\n", id));
    return;
  }

  if (reply[0] != ERQ_OK) {
    //debug_msg(sprintf("[AI_D] tcp_open_cb: open failed id=%d status=%d\n",
      //id, reply[0]));
    //fail(req, sprintf("ERQ_OPEN_TCP failed: %d", reply[0]));
    //cleanup(id);
    return;
  }

  ticket = reply[1..];
  req["ticket"] = ticket;

  debug_msg(sprintf("[AI_D] tcp_open_cb: open ok id=%d ticket=%O\n",
    id, ticket));

  body = json_serialize(req["payload"]);

  http =
    "POST " + AI_PATH + " HTTP/1.0\r\n"
    "Host: localhost\r\n"
    "Content-Type: application/json\r\n"
    "Content-Length: " + sizeof(body) + "\r\n"
    "Connection: close\r\n"
    "\r\n" +
    body;

  send_erq(
    ERQ_SEND,
    ticket + to_array(http),
    lambda(({ 'msg, 'len }), ({ #'tcp_read_cb, 'msg, id }))
  );

  debug_msg(sprintf("[AI_D] tcp_open_cb: sent http id=%d bytes=%d\n",
    id, sizeof(http)));
}

private void tcp_read_cb(mixed msg, int id) {
  mapping req;
  string chunk;
  int statuz;

  req = requests[id];
  if (!req) {
    debug_msg(sprintf("[AI_D] tcp_read_cb: missing request id=%d\n", id));
    return;
  }

  /* direct data chunks */
  if (stringp(msg) || bytesp(msg)) {
    chunk = stringp(msg) ? msg : to_text(msg, "utf-8");
    req["buffer"] += chunk;
    req["got_data"] = 1;
    req["updated_at"] = time();
    notify(req, "stream", chunk);
    debug_msg(sprintf("[AI_D] tcp_read_cb: chunk-id=%d len=%d\n",
      id, sizeof(chunk)));
    return;
  }

  if (intp(msg)) {
    debug_msg(sprintf("[AI_D] tcp_read_cb: int-msg-id=%d msg=%O\n",
      id, msg));
    deliver(req);
    cleanup(id);
    return;
  }

  if (!pointerp(msg) || !sizeof(msg)) {
    debug_msg(sprintf("[AI_D] tcp_read_cb: unexpected msg id=%d msg=%O\n",
      id, msg));
    return;
  }

  statuz = msg[0];

  /* control / ok */
  if (statuz == ERQ_OK) {
    if (sizeof(msg) > 1) {
      chunk = to_text(msg[1..], "utf-8");
      req["buffer"] += chunk;
      req["got_data"] = 1;
      req["updated_at"] = time();
      notify(req, "stream", chunk);
      debug_msg(sprintf("[AI_D] tcp_read_cb: ERQ_OK chunk-id=%d len=%d\n",
        id, sizeof(chunk)));
    }
    return;
  }

  if (statuz == ERQ_STDOUT) {
    if (sizeof(msg) > 1) {
      chunk = to_text(msg[1..], "utf-8");
      req["buffer"] += chunk;
      req["got_data"] = 1;
      req["updated_at"] = time();
      notify(req, "stream", chunk);
      debug_msg(sprintf("[AI_D] tcp_read_cb: ERQ_STDOUT chunk-id=%d len=%d\n",
        id, sizeof(chunk)));
    }
    return;
  }

  if (statuz == ERQ_EXITED) {
    debug_msg(sprintf("[AI_D] tcp_read_cb: ERQ_EXITED id=%d\n", id));
    deliver(req);
    cleanup(id);
    return;
  }

  debug_msg(sprintf("[AI_D] tcp_read_cb: unexpected status id=%d status=%d\n",
    id, statuz));
  fail(req, sprintf("unexpected ERQ status: %d", statuz));
  cleanup(id);
}

/* =========================================================
 * Result handling
 * ========================================================= */

private void deliver(mapping req) {
  string raw, body;
  int p;
  mixed parsed;

  raw = req["buffer"];
  body = raw;

  p = strstr(raw, "\r\n\r\n");
  if (p >= 0)
    body = raw[p + 4 ..];

  debug_msg(sprintf("[AI_D] deliver id=%d raw_len=%d body_len=%d\n",
    req["id"], sizeof(raw), sizeof(body)));

  parsed = 0;
  catch(parsed = json_parse(body));

  if (!parsed) {
    fail(req, "invalid JSON");
    return;
  }

  debug_msg(sprintf("[AI_D] deliver ok id=%d parsed=%O\n",
    req["id"], parsed));

  notify(req, "ok", parsed);
}

private void fail(mapping req, string msg) {
  debug_msg(sprintf("[AI_D] fail id=%d msg=%s\n", req["id"], msg));
  notify(req, "error", msg);
}

private void notify(mapping req, string statuz, mixed payload) {
  if (!objectp(req["cb_obj"]) || !stringp(req["cb_func"]))
    return;

  debug_msg(sprintf("[AI_D] notify id=%d status=%s cb_obj=%O cb_func=%s\n",
    req["id"], statuz, req["cb_obj"], req["cb_func"]));

  call_other(req["cb_obj"], req["cb_func"], statuz, payload, req["id"]);
}

private void cleanup(int id) {
  m_delete(requests, id);
  debug_msg(sprintf("[AI_D] cleanup id=%d\n", id));
}

/* =========================================================
 * Timeouts
 * ========================================================= */

public void check_timeouts() {
  int now, *ids, i;
  mapping req;

  now = time();
  ids = m_indices(requests);

  for (i = 0; i < sizeof(ids); i++) {
    req = requests[ids[i]];
    if (!req)
      continue;

    if (!req["got_data"] && now - req["started_at"] >= 10) {
      kill_request(req);
      fail(req, "no response from proxy");
      cleanup(ids[i]);
      continue;
    }

    if (now - req["started_at"] >= AI_TIMEOUT) {
      kill_request(req);
      fail(req, "timeout");
      cleanup(ids[i]);
    }
  }

  call_out("check_timeouts", AI_POLL_INTERVAL);
}

private void kill_request(mapping req) {
  if (pointerp(req["ticket"]))
    send_erq(ERQ_KILL, req["ticket"], 0);
}

private void request_read(mapping req, int id) {
  if (!pointerp(req["ticket"]))
    return;

  send_erq(
    ERQ_SEND,
    req["ticket"],
    lambda(({ 'msg, 'len }), ({ #'tcp_read_cb, 'msg, id }))
  );
}

void remove() {
  remove_call_out("check_timeouts");
}
