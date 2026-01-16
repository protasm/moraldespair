inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Back Lane";
  long_desc =
    "A small lane winds between cramped houses. Broken shutters lie in the weeds.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room250", "west",
    "domain/original/area/anshelm/room284", "east",
    "domain/original/area/anshelm/room1326", "north",
  });
}
