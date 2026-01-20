inherit "room/room";

void create() {
  ::create();

  short_desc = "Rotted Stalls";
  long_desc = "Stall frames lean inward, their rails splintered and gray. Dry straw rot and scattered nails litter the floor.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room224",
    "east":"/chapter/prologue/area/ruined/room222",
    "north":"/chapter/prologue/area/ruined/room120",
  ]);

  set_light(1);
}
