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
private int  start_request(mapping payload, object cb_obj, string cb_func);
private void tcp_open_cb(int *reply, int id);
private void tcp_read_cb(mixed msg, int id);
private void deliver(mapping req);
private void fail(mapping req, string msg);
private void notify(mapping req, string statuz, mixed payload);
private void cleanup(int id);
public  void check_timeouts();
private void kill_request(mapping req);

void create() {
  requests = ([]);
  next_id = 1;
  call_out("check_timeouts", AI_POLL_INTERVAL);
}

/* =========================================================
 * Public API
 * ========================================================= */

public int query(string prompt, object cb_obj, string cb_func) {
  if (!stringp(prompt))
    raise_error("AI_d->query(): prompt must be string\n");

  return start_request(([ "prompt" : prompt ]), cb_obj, cb_func);
}

public mapping statuz() {
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

  tell_object(this_player(), sprintf("[AI_D] request %d stored\n", id));

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
  if (!req)
    return;

  if (reply[0] != ERQ_OK)
    return;

  ticket = reply[1..];
  req["ticket"] = ticket;

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
}

private void tcp_read_cb(mixed msg, int id) {
  mapping req;
  string chunk;
  int statuz;

  req = requests[id];
  if (!req)
    return;

  /* direct data chunks */
  if (stringp(msg) || bytesp(msg)) {
    chunk = stringp(msg) ? msg : to_text(msg, "utf-8");
    req["buffer"] += chunk;
    req["got_data"] = 1;
    req["updated_at"] = time();
    notify(req, "stream", chunk);
    return;
  }

  if (intp(msg)) {
    deliver(req);
    cleanup(id);
    return;
  }

  if (!pointerp(msg) || !sizeof(msg))
    return;

  statuz = msg[0];

  /* control / ok */
  if (statuz == ERQ_OK) {
    if (sizeof(msg) > 1) {
      chunk = to_text(msg[1..], "utf-8");
      req["buffer"] += chunk;
      req["got_data"] = 1;
      req["updated_at"] = time();
      notify(req, "stream", chunk);
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
    }
    return;
  }

  if (statuz == ERQ_EXITED) {
    deliver(req);
    cleanup(id);
    return;
  }

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

  parsed = 0;
  catch(parsed = json_parse(body));

  if (!parsed) {
    fail(req, "invalid JSON");
    return;
  }

  notify(req, "ok", parsed);
}

private void fail(mapping req, string msg) {
  notify(req, "error", msg);
}

private void notify(mapping req, string statuz, mixed payload) {
  if (!objectp(req["cb_obj"]) || !stringp(req["cb_func"]))
    return;

  call_other(req["cb_obj"], req["cb_func"], statuz, payload, req["id"]);
}

private void cleanup(int id) {
  m_delete(requests, id);
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

void remove() {
  remove_call_out("check_timeouts");
}
