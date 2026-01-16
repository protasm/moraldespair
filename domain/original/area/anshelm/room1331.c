inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rose Altar";
  long_desc =
    "A small altar of stone stands against the wall, its carvings softened. Dried\n"
    "petals lie scattered in the dust.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1330", "west",
  });
}
