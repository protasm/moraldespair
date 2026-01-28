inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Foyer";
  long_desc = "A plain foyer opens onto several doorways, each stripped of its doors. The\nceiling has darkened with age.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room352",
    "south":"/chapter/prologue/area/silent/room350",
  ]);

  set_light(1);
}
