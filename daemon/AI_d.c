//
// daemon/AI_d.c
//
// Minimal AI daemon using ERQ/XERQ directly.
//

#pragma strong_types
#pragma save_types

#include <sys/erq.h>
#include "/daemon/AI_d.h"

#define AI_HOST_IP ({127,0,0,1})   // must be numeric for ERQ
#define AI_PORT 8000

private mapping requests;   // ticket -> request mapping
private int next_id;

void create() {
    requests = ([]);
    next_id = 1;
}

/* =========================================================
 * Public API
 * ========================================================= */

public int query(string prompt, object cb_obj, string cb_func) {
    mapping req;
    int *msg;

    if (!stringp(prompt))
        raise_error("AI_d->query(): prompt must be string\n");
    if (!objectp(cb_obj) || !stringp(cb_func))
        raise_error("AI_d->query(): bad callback\n");

    // ERQ_OPEN_TCP message:
    // [ ip1 ip2 ip3 ip4 port_hi port_lo ]
    msg = AI_HOST_IP + ({ AI_PORT / 256, AI_PORT & 255 });

    req = ([
        "id"      : next_id++,
        "prompt"  : prompt,
        "cb_obj"  : cb_obj,
        "cb_func" : cb_func,
        "buffer"  : "",
    ]);

    send_erq(
        ERQ_OPEN_TCP,
        msg,
        lambda(({ 'reply }),
            ({ #'tcp_open_cb, 'reply, req["id"] }))
    );

    requests[req["id"]] = req;
    return req["id"];
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

    if (reply[0] != ERQ_OK) {
        fail(req, "connection failed");
        return;
    }

    ticket = reply[1..];  // ERQ ticket

    req["ticket"] = ticket;

    body = json_serialize(([ "prompt" : req["prompt"] ]));

    http =
        "POST /query HTTP/1.1\r\n"
        "Host: localhost\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: " + sizeof(body) + "\r\n"
        "\r\n" +
        body;

    send_erq(
      ERQ_SEND | ERQ_CB_STRING,
      ticket + to_array(http),
      lambda(({ 'msg }),
        ({ #'tcp_read_cb, 'msg, id }))
);

}

private void tcp_read_cb(mixed msg, int id) {
    mapping req;

    req = requests[id];
    if (!req)
        return;

    /* STDOUT arrives as a STRING when ERQ_CB_STRING is set */
    if (stringp(msg)) {
        req["buffer"] += msg;
        return;
    }

    /* EXITED arrives as an INT */
    if (intp(msg)) {
        deliver(req);
        cleanup(id);
        return;
    }
}


/* =========================================================
 * Result handling
 * ========================================================= */

private void deliver(mapping req) {
    string raw, body;
    mixed parsed;

    raw = req["buffer"];
    if (!stringp(raw))
        return;

    if (strstr(raw, "\r\n\r\n") >= 0)
        body = raw[strstr(raw, "\r\n\r\n") + 4 ..];
    else
        body = raw;

    catch(parsed = json_parse(body));

    if (!parsed) {
        fail(req, "invalid JSON");
        return;
    }

    call_other(
        req["cb_obj"],
        req["cb_func"],
        "ok",
        parsed
    );
}

private void fail(mapping req, string msg) {
    call_other(
        req["cb_obj"],
        req["cb_func"],
        "error",
        msg
    );
}

private void cleanup(int id) {
    m_delete(requests, id);
}

/* =========================================================
 * Debug
 * ========================================================= */

public mapping req_status() {
    return copy(requests);
}

