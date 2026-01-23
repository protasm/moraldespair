//
// daemon/AI_d.c
//
// Production AI daemon using ERQ/XERQ.
//
// Request flow:
//   1) query_response()/query() builds a JSON payload and stores request state.
//   2) ERQ_OPEN_TCP opens the connection to the local proxy.
//   3) ERQ_SEND transmits the HTTP POST.
//   4) ERQ_STDOUT chunks stream through tcp_read_cb() and are forwarded to the
//      caller via cb_obj/cb_func as "stream" messages, while also buffering.
//   5) ERQ_EXITED triggers final JSON parsing and a single "ok" callback.
//   6) Errors or timeouts trigger "error" callbacks and cleanup.
//
// Callback routing:
//   call_other(cb_obj, cb_func, status, payload, request_id)
//   status is one of: "stream", "ok", "error".
//
// Proxy configuration:
//   Adjust AI_HOST_IP/AI_PORT/AI_PATH for your local HTTP proxy. TLS is
//   expected to be handled externally by that proxy.
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

private int start_request(mapping payload, object cb_obj, string cb_func);
private void tcp_open_cb(int *reply, int id);
private void tcp_read_cb(mixed msg, int id);
private void deliver(mapping req);
private void fail(mapping req, string msg);
private void notify(mapping req, string status, mixed payload);
private void cleanup(int id);
private void check_timeouts();
private void kill_request(mapping req);

void create() {
  requests = ([]);
  next_id = 1;

  call_out("check_timeouts", AI_POLL_INTERVAL);
}

/* =========================================================
 * Public API
 * ========================================================= */

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

  payload = ([
    "npc_id" : npc_id,
    "player_id" : player_id,
    "event" : event,
    "context" : context,
    "options" : options,
  ]);

  return start_request(payload, cb_obj, cb_func);
}

public int query(string prompt, object cb_obj, string cb_func) {
  mapping payload;

  if (!stringp(prompt))
    raise_error("AI_d->query(): prompt must be string\n");

  payload = ([ "prompt" : prompt ]);

  return start_request(payload, cb_obj, cb_func);
}

public mapping req_status() {
  return copy(requests);
}

/* =========================================================
 * Internal request handling
 * ========================================================= */

private int start_request(mapping payload, object cb_obj, string cb_func) {
  mapping req;
  int id;
  int *msg;

  if (!objectp(cb_obj) || !stringp(cb_func))
    raise_error("AI_d->start_request(): bad callback\n");

  id = next_id;
  next_id += 1;

  req = ([
    "id" : id,
    "payload" : payload,
    "cb_obj" : cb_obj,
    "cb_func" : cb_func,
    "buffer" : "",
    "started_at" : time(),
    "updated_at" : time(),
  ]);

  requests[id] = req;

  msg = AI_HOST_IP + ({ AI_PORT / 256, AI_PORT & 255 });

  send_erq(
    ERQ_OPEN_TCP,
    msg,
    lambda(({ 'reply }),
      ({ #'tcp_open_cb, 'reply, id }))
  );

  return id;
}

/* =========================================================
 * ERQ callbacks
 * ========================================================= */

private void tcp_open_cb(int *reply, int id) {
  mapping req;
  int *ticket;
  string body;
  string http;
  string headers;

  req = requests[id];
  if (!req)
    return;

  if (reply[0] != ERQ_OK) {
    fail(req, "connection failed");
    cleanup(id);
    return;
  }

  ticket = reply[1..];
  req["ticket"] = ticket;
  req["updated_at"] = time();

  body = json_serialize(req["payload"]);

  headers =
    "POST " + AI_PATH + " HTTP/1.1\r\n"
    "Host: localhost\r\n"
    "Content-Type: application/json\r\n"
    "Content-Length: " + sizeof(body) + "\r\n"
    "Connection: close\r\n";

  http = headers + "\r\n" + body;

  send_erq(
    ERQ_SEND | ERQ_CB_STRING,
    ticket + to_array(http),
    lambda(({ 'msg }),
      ({ #'tcp_read_cb, 'msg, id }))
  );
}

private void tcp_read_cb(mixed msg, int id) {
  mapping req;
  string chunk;

  req = requests[id];
  if (!req)
    return;

  if (stringp(msg)) {
    chunk = msg;

    req["buffer"] += chunk;
    req["updated_at"] = time();

    notify(req, "stream", chunk);
    return;
  }

  if (intp(msg)) {
    deliver(req);
    cleanup(id);
    return;
  }

  fail(req, "unexpected ERQ message");
  cleanup(id);
}

/* =========================================================
 * Result handling
 * ========================================================= */

private void deliver(mapping req) {
  string raw;
  string body;
  int header_end;
  mixed parsed;

  raw = req["buffer"];
  body = raw;

  header_end = strstr(raw, "\r\n\r\n");
  if (header_end >= 0)
    body = raw[header_end + 4 ..];

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

private void notify(mapping req, string status, mixed payload) {
  object cb_obj;
  string cb_func;

  cb_obj = req["cb_obj"];
  cb_func = req["cb_func"];

  if (!objectp(cb_obj) || !stringp(cb_func))
    return;

  call_other(cb_obj, cb_func, status, payload, req["id"]);
}

private void cleanup(int id) {
  m_delete(requests, id);
}

/* =========================================================
 * Timeouts
 * ========================================================= */

private void check_timeouts() {
  int now;
  int *ids;
  int i;
  mapping req;

  now = time();
  ids = m_indices(requests);

  for (i = 0; i < sizeof(ids); i += 1) {
    req = requests[ids[i]];
    if (!req)
      continue;

    if ((now - req["started_at"]) >= AI_TIMEOUT) {
      kill_request(req);
      fail(req, "timeout");
      cleanup(ids[i]);
    }
  }

  call_out("check_timeouts", AI_POLL_INTERVAL);
}

private void kill_request(mapping req) {
  int *ticket;

  ticket = req["ticket"];
  if (!pointerp(ticket))
    return;

  send_erq(ERQ_KILL, ticket, 0);
}
