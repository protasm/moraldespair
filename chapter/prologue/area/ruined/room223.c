inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Rotted Stalls";
  long_desc = "Stall frames lean inward, their rails splintered and gray. Dry straw rot and scattered nails litter the floor.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room224", "west",
    "chapter/prologue/area/ruined/room222", "east",
    "chapter/prologue/area/ruined/room120", "north",
  });
}
