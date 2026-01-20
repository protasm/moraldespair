inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Weathered Path";
  long_desc = "The way is reduced to uneven slabs, their edges rounded and split by long neglect. Silt and mildew pool in the seams, and the path fades into quiet stonework to either side.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room194", "east",
    "chapter/prologue/area/ruined/room137", "west",
  });
}
