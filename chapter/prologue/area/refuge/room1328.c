inherit "room/room";

void create() {
  ::create();

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward the outer wall, its paving split and worn. A heap of\n"
    "fallen bricks blocks one old doorway.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1329",
    "west" : "/chapter/prologue/area/refuge/room281",
  ]);

  set_light(1);
}
