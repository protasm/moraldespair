inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Stalls";
  long_desc = "Stall frames lean inward, their rails broken and dulled by\n"
              + "age. Dry straw rot and scattered nails cling to the floor.\n";
  dest_dir = ({
    "domain/original/area/vesla/room224", "west",
    "domain/original/area/vesla/room222", "east",
    "domain/original/area/vesla/room120", "north",
  });
}
