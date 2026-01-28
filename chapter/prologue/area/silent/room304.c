inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "The roadbed dips where the ground has settled. Broken walls crowd close on\neither side.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room305",
    "east":"/chapter/prologue/area/silent/room303",
    "north":"/chapter/prologue/area/silent/room330",
  ]);

  set_light(1);
}
