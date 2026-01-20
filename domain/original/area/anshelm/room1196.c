inherit "room/room";

void create() {
  ::create();

  short_desc = "Halfbuilt Hall";
  long_desc =
    "Half-raised walls stand in a rectangle, their courses uneven and cracked. Old\n"
    "scaffolding poles lie snapped across the ground.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1195", "east",
  });

  set_light(1);
}
