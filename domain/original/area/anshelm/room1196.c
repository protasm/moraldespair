inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Halfbuilt Hall";
  long_desc =
    "Half-raised walls stand in a rectangle, their courses uneven and cracked. Old\n"
    "scaffolding poles lie snapped across the ground.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1195", "east",
  });
}
