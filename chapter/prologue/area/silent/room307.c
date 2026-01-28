inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Road End";
  long_desc = "The road narrows and loses its paving in a drift of soil. Beyond it, the track\ndissolves into grass.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room306",
    "northwest":"/chapter/prologue/area/silent/room331",
    "south":"/chapter/prologue/area/silent/room308",
  ]);

  set_light(1);
}
