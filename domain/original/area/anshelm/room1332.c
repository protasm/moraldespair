inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "South Statuary";
  long_desc =
    "Broken statues lean against the south wall, their faces worn blank. Fragments\n"
    "of marble litter the floor.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1330", "north",
  });
}
