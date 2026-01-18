inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc = "The street has sagged and cracked, letting patches of weeds break through the seams. A fallen crossbeam lies against the wall, its fittings scarred as if something once hung there and rang.";
  dest_dir = ({
    "domain/original/area/vesla/room202", "east",
    "domain/original/area/vesla/room204", "west",
  });
}
