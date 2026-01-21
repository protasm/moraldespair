inherit "room/room";

void create() {
  ::create();

  short_desc = "Shadow Bend";
  long_desc = "A tight bend hides the alley from the street, keeping it dark and stale. The\nwalls are pocked with old nail holes and cracks.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room325",
    "north":"/chapter/prologue/area/silent/room327",
  ]);

  set_light(1);
}
