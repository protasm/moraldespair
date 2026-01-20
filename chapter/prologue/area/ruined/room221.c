inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Counter";
  long_desc = "A long counter sags under its own weight, split and furred with dust. Behind it, shelves lie in heaps, and the air is stale and still.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room222",
    "east":"/chapter/prologue/area/ruined/room220",
    "north":"/chapter/prologue/area/ruined/room118",
  ]);

  set_light(1);
}
