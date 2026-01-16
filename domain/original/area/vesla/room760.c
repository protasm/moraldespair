inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Lower Steps";
  long_desc = "These steps descend into damp shadow, their edges rounded and slick\n"
    "with moss. A crumbling handrail line and iron pegs show where the\n"
    "stair was once kept tight.\n";
  dest_dir = ({
    "domain/original/area/vesla/room759", "southwest",
    "domain/original/area/vesla/room761", "up",
  });
}
