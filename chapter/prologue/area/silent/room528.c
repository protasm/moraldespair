inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "The path is straight and formal, though its stones have shifted. Silent\nfacades rise on both sides.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room896",
    "east":"/chapter/prologue/area/silent/room894",
    "north":"/chapter/prologue/area/silent/room527",
  ]);

  set_light(1);
}
