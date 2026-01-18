inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward the outer wall, its paving split and worn. A heap of\n"
    "fallen bricks blocks one old doorway.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1329", "east",
    "domain/original/area/anshelm/room281", "west",
  });
}
