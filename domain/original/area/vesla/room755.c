inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Tower Gap";
  long_desc = "The gap between the towers narrows here, with soot-dark stone and\n"
    "warped iron bands clinging to the walls. The floor is littered with\n"
    "crumbling mortar and a rot-stained beam that once barred the way.\n";
  dest_dir = ({
    "domain/original/area/vesla/room754", "south",
    "domain/original/area/vesla/room756", "north",
  });
}
