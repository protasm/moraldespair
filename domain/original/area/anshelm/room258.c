inherit "room/room";

void create() {
  ::create();

  short_desc = "Market Crossing";
  long_desc =
    "Two streets intersect around a scatter of broken paving. A split wagon wheel\n"
    "rests in the gutter.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room259", "west",
    "domain/original/area/anshelm/room281", "east",
    "domain/original/area/anshelm/room257", "south",
  });

  set_light(1);
}
