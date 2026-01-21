inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Lawn";
  long_desc = "Broken statues stand amid tall grass, their faces worn away. Plinths sit\ncracked and empty where others fell.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room344",
    "north":"/chapter/prologue/area/silent/room340",
  ]);

  set_light(1);
}
