inherit "room/room";

#include <erq.h>

/* -------------------------
 * Forward declarations
 * ------------------------- */
int erqtest();
int tcptest();
int aitest(string str);

void tcp_cb(int *data, int len);
void send_http();

/* -------------------------
 * State
 * ------------------------- */
static int *tcp_ticket;
static object tcptest_who;

/* -------------------------
 * Room setup
 * ------------------------- */
void create() {
  ::create();

  short_desc = "Players' Lounge";
  long_desc =
    "You stand in the hollowed remains of the lounge, a room that once buzzed "
    "with the gossip and fevered arguments of long-dead legends. Now, the only "
    "sound is the whistling of wind through the cracked, soot-stained windows "
    "that line the walls. A shimmering blue portal still flickers weakly in the "
    "center, its light pulsing like a dying heart as it leads upward.\n\n"
    "You may test the whispering machinery with:\n"
    "  erqtest\n"
    "  tcptest\n"
    "  aitest <prompt>\n";

  dest_dir = ([
    "down": "/chapter/prologue/area/ruined/sanctuary",
  ]);

  set_light(1);
}

void init() {
  ::init();
  add_action("erqtest", "erqtest");
  add_action("tcptest", "tcptest");
  add_action("aitest", "aitest");
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
 * TCP + HTTP test
 * ------------------------- */
int tcptest() {
  int *addr;

  tcptest_who = this_player();
  if (!tcptest_who) return 0;

  tell_object(tcptest_who,
    "Opening TCP to 127.0.0.1:8000...\n");

  addr = ({ 127,0,0,1, 8000>>8, 8000&255 });

  tcp_ticket = 0;

  send_erq(
    ERQ_OPEN_TCP,
    addr,
    #'tcp_cb
  );

  return 1;
}

void send_http() {
  int *req;
  object who;

  who = tcptest_who;
  if (who)
    tell_object(who, "Sending HTTP GET...\n");

  req = to_array(to_bytes(
    "GET / HTTP/1.0\r\n"
    "Host: localhost\r\n"
    "\r\n",
    "ascii"
  ));

  send_erq(ERQ_SEND, tcp_ticket + req, 0);
}

void tcp_cb(int *data, int len) {
  object who;

  who = tcptest_who;
  if (!who || !pointerp(data) || !sizeof(data))
    return;

  switch (data[0]) {

    case ERQ_OK:
      if (!tcp_ticket) {
        tcp_ticket = data[1..];
        tell_object(who,
          "TCP connected, ticket stored.\n");
        send_http();
      }
      return;

    case ERQ_STDOUT:
      tell_object(who, to_string(data[1..]) + "\n");
      return;

    case ERQ_EXITED:
      tell_object(who,
        "Connection closed.\n");
      return;

    default:
      tell_object(who,
        sprintf("ERQ event: %O\n", data));
      return;
  }
}

/* -------------------------
 * AI test placeholder
 * ------------------------- */
int aitest(string str) {
  object who;

  who = this_player();
  if (!who) return 0;

  if (!str || str == "") {
    tell_object(who,
      "Usage: aitest <prompt>\n");
    return 1;
  }

  tell_object(who,
    "You whisper into the unseen machinery...\n");

  /* Hook point for daemon/AI_d */
  return 1;
}
