inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Rotted Stalls";
  long_desc = "Stall frames lean inward, their rails splintered and\n"
              + "gray.\n"
              + "Dry straw rot and scattered nails litter the floor.\n";
  dest_dir = ({
    "domain/original/area/vesla/room224", "west",
    "domain/original/area/vesla/room222", "east",
    "domain/original/area/vesla/room120", "north",
  });
}
