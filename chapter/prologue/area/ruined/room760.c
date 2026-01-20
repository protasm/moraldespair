inherit "room/room";

void create() {
  ::create();

  short_desc = "Lower Steps";
  long_desc = "These steps descend into damp shadow, their edges rounded and slick with moss. A crumbling handrail line and iron pegs show where the stair was once kept tight.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room759", "southwest",
    "chapter/prologue/area/ruined/room761", "up",
  });

  set_light(1);
}
