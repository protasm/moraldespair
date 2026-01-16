inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Bridge";
  long_desc =
    "The drawbridge sags at its chains, its planks split and dark. A dry moat lies\n"
    "beneath, scattered with fallen stone.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room255", "east",
    "domain/original/area/anshelm/room1196", "west",
  });
}
