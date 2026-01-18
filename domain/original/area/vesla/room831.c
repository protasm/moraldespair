inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Lower Office";
  long_desc = "Long desks sit in a row, their legs sunk into a drift of dust. A rusted bell and cracked inkwells remain, and mildew has spread along the baseboards.";
  dest_dir = ({
    "domain/original/area/vesla/room833", "up",
    "domain/original/area/vesla/room822", "down",
    "domain/original/area/vesla/room832", "west",
  });
}
