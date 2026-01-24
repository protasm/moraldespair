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
private string indent_prefix(int depth);
private string pretty_value(mixed value, int depth);
private string pretty_mapping(mapping data, int depth);
private string pretty_array(mixed *data, int depth);
private int  start_request(mapping payload, object cb_obj, string cb_func);
private void tcp_open_cb(int *reply, int id);
private void tcp_send_cb(mixed msg, int id);
private void tcp_read_cb(mixed msg, int id);
private void deliver(mapping req);
private mapping split_response(string raw);
private int parse_content_length(string headers);
private string dechunk(string body);
private string normalize_chunk(mixed msg);
private string read_chunk(mixed msg);
private mapping decode_reply(mixed msg);
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

private string indent_prefix(int depth) {
  string pad;
  int i;

  pad = "";

  for (i = 0; i < depth; i++)
    pad += "  ";

  return pad;
}

private string pretty_value(mixed value, int depth) {
  if (mappingp(value))
    return pretty_mapping(value, depth);

  if (pointerp(value))
    return pretty_array(value, depth);

  return sprintf("%O", value);
}

private string pretty_mapping(mapping data, int depth) {
  string out, pad, inner_pad;
  mixed *keys;
  int i;

  if (!mappingp(data))
    return sprintf("%O", data);

  keys = m_indices(data);
  pad = indent_prefix(depth);
  inner_pad = indent_prefix(depth + 1);
  out = "([\n";

  for (i = 0; i < sizeof(keys); i++) {
    out += inner_pad + sprintf("%O", keys[i]) + " : ";
    out += pretty_value(data[keys[i]], depth + 1);
    if (i < sizeof(keys) - 1)
      out += ",\n";
    else
      out += "\n";
  }

  out += pad + "])";

  return out;
}

private string pretty_array(mixed *data, int depth) {
  string out, pad, inner_pad;
  int i;

  if (!pointerp(data))
    return sprintf("%O", data);

  pad = indent_prefix(depth);
  inner_pad = indent_prefix(depth + 1);
  out = "({\n";

  for (i = 0; i < sizeof(data); i++) {
    out += inner_pad + pretty_value(data[i], depth + 1);
    if (i < sizeof(data) - 1)
      out += ",\n";
    else
      out += "\n";
  }

  out += pad + "})";

  return out;
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
  debug_msg("[AI_D] query payload\n" + pretty_mapping(payload, 0) + "\n");

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
  debug_msg("[AI_D] request stored mapping\n" + pretty_mapping(req, 0) + "\n");

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
    ERQ_SEND | ERQ_CB_STRING,
    ticket + to_array(http),
    lambda(({ 'msg, 'len }), ({ #'tcp_send_cb, 'msg, id }))
  );

  debug_msg(sprintf("[AI_D] tcp_open_cb: sent http id=%d bytes=%d\n",
    id, sizeof(http)));
}

private void tcp_send_cb(mixed msg, int id) {
  mapping req;

  req = requests[id];
  if (!req) {
    debug_msg(sprintf("[AI_D] tcp_send_cb: missing request id=%d\n", id));
    return;
  }

  if (intp(msg)) {
    debug_msg(sprintf("[AI_D] tcp_send_cb: int-msg-id=%d msg=%O\n", id, msg));
    if (msg != ERQ_OK) {
      fail(req, sprintf("ERQ_SEND failed: %d", msg));
      cleanup(id);
      return;
    }

    request_read(req, id);
    return;
  }

  if (!pointerp(msg) || !sizeof(msg)) {
    debug_msg(sprintf("[AI_D] tcp_send_cb: unexpected msg id=%d msg=%O\n",
      id, msg));
    return;
  }

  if (msg[0] != ERQ_OK) {
    debug_msg(sprintf("[AI_D] tcp_send_cb: send failed id=%d status=%d\n",
      id, msg[0]));
    fail(req, sprintf("ERQ_SEND failed: %d", msg[0]));
    cleanup(id);
    return;
  }

  request_read(req, id);
}

private void tcp_read_cb(mixed msg, int id) {
  mapping req;
  string type, stdout_data;
  object watcher;

  req = requests[id];
  if (!req) {
    debug_msg(sprintf("[AI_D] tcp_read_cb: missing request id=%d\n", id));
    return;
  }

  if (stringp(msg))
    type = "string";
  else if (bytesp(msg))
    type = "bytes";
  else if (intp(msg))
    type = "int";
  else if (pointerp(msg))
    type = "array";
  else
    type = "unknown";

  watcher = find_player("solfeggio");
  if (objectp(watcher)) {
    tell_object(watcher,
      sprintf("[AI_PROBE] tcp_read_cb id=%d type=%s msg=%O\n", id, type, msg));
  }

  if (pointerp(msg) && sizeof(msg) && msg[0] == ERQ_STDOUT) {
    stdout_data = normalize_chunk(msg[1..]);
    if (objectp(watcher)) {
      tell_object(watcher, "[AI_PROBE] RECEIVED STDOUT DATA:\n");
      tell_object(watcher, stdout_data + "\n");
    }
  }

  if (pointerp(msg) && sizeof(msg) && msg[0] == ERQ_E_TICKET) {
    if (objectp(watcher))
      tell_object(watcher, "[AI_PROBE] ERQ_E_TICKET received\n");
  }

  return;
}

/* =========================================================
 * Result handling
 * ========================================================= */

private void deliver(mapping req) {
  string raw, body, headers, lower_headers;
  mapping split;
  int content_length;
  mixed parsed;

  raw = req["buffer"];
  split = split_response(raw);
  headers = split["headers"];
  body = split["body"];

  if (!sizeof(headers) && strstr(raw, "HTTP/") == 0) {
    fail(req, "incomplete HTTP response");
    return;
  }

  lower_headers = lower_case(headers);
  if (strstr(lower_headers, "transfer-encoding: chunked") >= 0)
    body = dechunk(body);

  content_length = parse_content_length(headers);
  if (content_length >= 0) {
    if (sizeof(body) < content_length) {
      fail(req, "incomplete response body");
      return;
    }

    if (content_length == 0)
      body = "";
    else
      body = body[0..content_length - 1];
  }

  body = trim(body);

  debug_msg("raw: >>" + raw + "<<\n");
  debug_msg("body: >>" + body + "<<\n");

  debug_msg(
    sprintf("[AI_D] deliver id=%d raw_len=%d body_len=%d\n",
    req["id"], sizeof(raw), sizeof(body))
  );

  if (!sizeof(body)) {
    fail(req, "empty response body");
    return;
  }

  parsed = 0;
  catch(parsed = json_parse(body));

  if (!parsed) {
    fail(req, "invalid JSON");
    return;
  }

  debug_msg(sprintf("[AI_D] deliver ok id=%d parsed=%O\n",
    req["id"], parsed));
  if (mappingp(parsed)) {
    debug_msg("[AI_D] deliver parsed mapping\n"
      + pretty_mapping(parsed, 0) + "\n");
  }

  notify(req, "ok", parsed);
}

private mapping split_response(string raw) {
  string headers, body;
  int p;

  headers = "";
  body = raw;

  p = strstr(raw, "\r\n\r\n");
  if (p >= 0) {
    headers = raw[0..p - 1];
    body = raw[p + 4 ..];
  } else {
    p = strstr(raw, "\n\n");
    if (p >= 0) {
      headers = raw[0..p - 1];
      body = raw[p + 2 ..];
    }
  }

  return ([
    "headers" : headers,
    "body"    : body,
  ]);
}

private int parse_content_length(string headers) {
  string *lines;
  string line, lower;
  int i;
  int length;

  if (!sizeof(headers))
    return -1;

  lines = explode(headers, "\n");
  length = -1;

  for (i = 0; i < sizeof(lines); i++) {
    line = trim(lines[i]);
    lower = lower_case(line);

    if (sscanf(lower, "content-length: %d", length) == 1)
      return length;
  }

  return -1;
}

private string dechunk(string body) {
  string out, rest, size_line, chunk;
  int size, p;

  out = "";
  rest = body;

  while (sizeof(rest)) {
    p = strstr(rest, "\r\n");
    if (p < 0) {
      p = strstr(rest, "\n");
      if (p < 0)
        break;

      size_line = rest[0..p - 1];
      rest = rest[p + 1 ..];
    } else {
      size_line = rest[0..p - 1];
      rest = rest[p + 2 ..];
    }

    size = 0;
    if (sscanf(size_line, "%x", size) != 1)
      break;

    if (size == 0)
      break;

    if (sizeof(rest) < size)
      break;

    chunk = rest[0..size - 1];
    out += chunk;
    rest = rest[size ..];

    if (sizeof(rest) >= 2 && rest[0..1] == "\r\n")
      rest = rest[2 ..];
    else if (sizeof(rest) >= 1 && rest[0..0] == "\n")
      rest = rest[1 ..];
  }

  return out;
}

private string normalize_chunk(mixed msg) {
  bytes raw;

  if (stringp(msg))
    return msg;

  if (bytesp(msg))
    return to_text(msg, "utf-8");

  if (pointerp(msg)) {
    raw = to_bytes(msg);

    return to_text(raw, "utf-8");
  }

  return "";
}

private string read_chunk(mixed msg) {
  if (stringp(msg) || bytesp(msg))
    return normalize_chunk(msg);

  if (pointerp(msg)) {
    if (sizeof(msg) < 2)
      return "";

    if (stringp(msg[1]) || bytesp(msg[1]))
      return normalize_chunk(msg[1]);

    if (pointerp(msg[1]))
      return normalize_chunk(msg[1]);

    return normalize_chunk(msg[1..]);
  }

  return "";
}

private mapping decode_reply(mixed msg) {
  int *raw;
  int statuz;
  string chunk;

  raw = 0;
  statuz = ERQ_E_INCOMPLETE;
  chunk = "";

  if (intp(msg)) {
    return ([
      "status" : msg,
      "data"   : "",
    ]);
  }

  if (stringp(msg))
    raw = to_array(msg);
  else if (bytesp(msg))
    raw = to_array(to_text(msg, "utf-8"));
  else if (pointerp(msg))
    raw = msg;

  if (!pointerp(raw) || !sizeof(raw)) {
    return ([
      "status" : ERQ_E_INCOMPLETE,
      "data"   : "",
    ]);
  }

  statuz = raw[0];
  if (sizeof(raw) > 1)
    chunk = normalize_chunk(raw[1..]);

  return ([
    "status" : statuz,
    "data"   : chunk,
  ]);
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
  if (mappingp(payload)) {
    debug_msg("[AI_D] notify mapping payload\n"
      + pretty_mapping(payload, 0) + "\n");
  }

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
