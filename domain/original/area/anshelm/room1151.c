inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Stair";
  long_desc =
    "The stairwell narrows as it rises, with crumbling plaster exposing rough\n"
    "stone. Iron nails protrude where a railing once stood.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1149", "down",
    "domain/original/area/anshelm/room1152", "up",
  });
}
