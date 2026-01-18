inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Chamber";
  long_desc =
    "The chamber is broad but empty, with a roof caved in at one end. Charred beams\n"
    "lie across the floor.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1160", "east",
    "domain/original/area/anshelm/room1162", "west",
  });
}
