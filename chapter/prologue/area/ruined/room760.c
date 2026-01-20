inherit "room/room";

void create() {
  ::create();

  short_desc = "Lower Steps";
  long_desc = "These steps descend into damp shadow, their edges rounded and slick with moss. A crumbling handrail line and iron pegs show where the stair was once kept tight.";
  dest_dir = ([
    "southwest":"/chapter/prologue/area/ruined/room759",
    "up":"/chapter/prologue/area/ruined/room761",
  ]);

  set_light(1);
}
