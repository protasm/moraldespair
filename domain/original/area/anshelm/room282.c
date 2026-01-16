inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Gap";
  long_desc =
    "A tight passage squeezes between two leaning walls. The stone here is smooth\n"
    "with wear and damp.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room265", "east",
  });
}
