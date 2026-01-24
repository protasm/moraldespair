inherit "room/room";

#include <sys/erq.h>

/* -------------------------
 * Forward declarations
 * ------------------------- */
int erqtest();
int aitest(string str);
void ai_cb(string req_status, mixed payload, int request_id);
void debug_msg(string msg);

/* -------------------------
 * State
 * ------------------------- */
private mapping ai_requests;

/* -------------------------
 * Room setup
 * ------------------------- */
void create() {
  ::create();
  ai_requests = ([]);

  short_desc = "Players' Lounge";
  long_desc =
    "You stand in the hollowed remains of the lounge, a room that once buzzed "
    "with the gossip and fevered arguments of long-dead legends. Now, the only "
    "sound is the whistling of wind through the cracked, soot-stained windows "
    "that line the walls. A shimmering blue portal still flickers weakly in the "
    "center, its light pulsing like a dying heart as it leads upward.\n\n"
    "You may test the whispering machinery with:\n"
    "  erqtest\n"
    "  aitest <prompt>\n";

  dest_dir = ([
    "down": "/chapter/prologue/area/ruined/sanctuary",
  ]);

  set_light(1);
}

void debug_msg(string msg) {
  object watcher;

  watcher = find_player("solfeggio");
  if (!objectp(watcher))
    return;

  tell_object(watcher, msg);
}

void init() {
  ::init();
  add_action("erqtest", "erqtest");
  add_action("aitest", "aitest");
  add_action("erqlookuptest", "erqlookuptest");
}

/* -------------------------
 * ERQ LOOKUP test
 * ------------------------- */
int erqtest() {
  bytes host;
  object who;

  who = this_player();
  if (!who) return 0;

  tell_object(who, "Sending ERQ_LOOKUP for localhost...\n");

  host = to_bytes("localhost", "ascii");

  send_erq(
    ERQ_LOOKUP,
    host,
    lambda(({ 'data, 'len }),
      ({
        #'tell_object,
        who,
        ({ #'sprintf,
           "ERQ_LOOKUP callback: data=%O len=%d\n",
           'data, 'len })
      })
    )
  );

  return 1;
}

/* -------------------------
 * AI test placeholder
 * ------------------------- */
int aitest(string str) {
  object who;
  int request_id;

  who = this_player();
  if (!who) return 0;

  if (!str || str == "") {
    tell_object(who,
      "Usage: aitest <prompt>\n");
    return 1;
  }

  debug_msg(sprintf("[LOUNGE] aitest who=%O prompt_len=%d\n",
    who, sizeof(str)));

  tell_object(who,
    "You whisper into the unseen machinery...\n");

  request_id = "/daemon/AI_d"->query(str, this_object(), "ai_cb");

  if (!request_id) {
    debug_msg(sprintf("[LOUNGE] aitest failed request_id=%d\n", request_id));
    tell_object(who, "The machinery does not answer.\n");
    return 1;
  }

  ai_requests[request_id] = who;

  debug_msg(sprintf("[LOUNGE] aitest stored request_id=%d\n", request_id));

  return 1;
}

void ai_cb(string req_status, mixed payload, int request_id) {
  object who;

  debug_msg(sprintf("[LOUNGE] ai_cb status=%s id=%d payload=%O\n",
    req_status, request_id, payload));

  who = ai_requests[request_id];
  if (!who) return;

  tell_object(who,
    sprintf("[AI_CB] status=%s id=%d payload=%O\n",
            req_status, request_id, payload));

  if (req_status == "ok" || req_status == "error")
    m_delete(ai_requests, request_id);
}

int erqlookuptest() {
  send_erq(
    ERQ_LOOKUP,
    to_bytes("localhost", "ascii"),
    lambda(({ 'data, 'len }),
      ({ #'tell_object, this_player(), "[ERQ_LOOKUP callback fired]\n" })
    )
  );
  return 1;
}
