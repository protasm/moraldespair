inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Market Crossing";
  long_desc =
    "Two streets intersect around a scatter of broken paving. A split wagon wheel\n"
    "rests in the gutter.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room259", "west",
    "domain/original/area/anshelm/room281", "east",
    "domain/original/area/anshelm/room257", "south",
  });
}
