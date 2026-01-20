inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Hall";
  long_desc = "The hall is hollow, its banners reduced to rags and mildew. Worn planks and a stone dais hint at oaths and instruction that ended long ago.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room126", "north",
  });
}
