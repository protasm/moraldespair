inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Sooted Row";
  long_desc = "Soot stains the surviving walls, and the lane sits in a hush of rot and dust.\n"
        + "Warped shutters and mildewed frames lean inward, the fire-scarred row left in\n"
        + "collapse and silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room147", "south",
    "domain/original/area/vesla/room842", "west",
    "domain/original/area/vesla/room840", "east",
    "domain/original/area/vesla/room843", "north",
  });
}
