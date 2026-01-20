inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Gap";
  long_desc =
    "A tight passage squeezes between two leaning walls. The stone here is smooth\n"
    "with wear and damp.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room265", "east",
  });

  set_light(1);
}
