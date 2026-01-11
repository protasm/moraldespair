inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Hall";
  long_desc = "The hall is hollow, its banners reduced to rags and mildew. Worn planks and a\n"
              + "stone dais hint at oaths and instruction that ended long ago.\n";
  dest_dir = ({
    "domain/original/area/vesla/room126", "north",
  });
}
