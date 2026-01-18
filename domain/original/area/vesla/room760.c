inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Lower Steps";
  long_desc = "These steps descend into damp shadow, their edges rounded and slick with moss. A crumbling handrail line and iron pegs show where the stair was once kept tight.";
  dest_dir = ({
    "domain/original/area/vesla/room759", "southwest",
    "domain/original/area/vesla/room761", "up",
  });
}
