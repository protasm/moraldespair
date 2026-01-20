inherit "room/room";

void create() {
  ::create();

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward the outer wall, its paving split and worn. A heap of\n"
    "fallen bricks blocks one old doorway.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1329", "east",
    "chapter/prologue/area/anshelm/room281", "west",
  });

  set_light(1);
}
