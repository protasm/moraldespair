inherit "room/room";

void create() {
  ::create();

  short_desc = "Sentry Street";
  long_desc =
    "The street is broader here, with a strip of packed earth between stones. A\n"
    "toppled post leans against a wall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room268",
    "west" : "/chapter/prologue/area/anshelm/room270",
  ]);

  set_light(1);
}
