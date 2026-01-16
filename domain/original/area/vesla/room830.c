inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Oven";
  long_desc = "The room is thick with old flour dust and collapsed racks, the stone\n"
    "floor sticky with mildew. A soot-dark oven mouth gapes in the back\n"
    "wall, long since cold.\n";
  dest_dir = ({
    "domain/original/area/vesla/room157", "west",
  });
}
