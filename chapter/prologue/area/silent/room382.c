inherit "room/room";

void create() {
  ::create();

  short_desc = "Cemetery Gate";
  long_desc = "An iron gate hangs open on one hinge, set in a low stone wall. The ground\nbeyond is uneven with old graves.\n";
  dest_dir = ([
    "northwest":"/chapter/prologue/area/silent/room380",
  ]);

  set_light(1);
}
