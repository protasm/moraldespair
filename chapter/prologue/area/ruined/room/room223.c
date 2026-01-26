inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Rotted Stalls";
  long_desc = "Stall frames lean inward, their rails splintered and gray. Dry straw rot and scattered nails litter the floor.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room224",
    "east":"/chapter/prologue/area/ruined/room/room222",
    "north":"/chapter/prologue/area/ruined/room/room120",
  ]);

}
