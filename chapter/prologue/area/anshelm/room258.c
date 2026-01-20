inherit "room/room";

void create() {
  ::create();

  short_desc = "Market Crossing";
  long_desc =
    "Two streets intersect around a scatter of broken paving. A split wagon wheel\n"
    "rests in the gutter.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room259", "west",
    "chapter/prologue/area/anshelm/room281", "east",
    "chapter/prologue/area/anshelm/room257", "south",
  });

  set_light(1);
}
