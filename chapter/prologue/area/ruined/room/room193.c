inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Weathered Path";
  long_desc = "The way is reduced to uneven slabs, their edges rounded and split by long neglect. Silt and mildew pool in the seams, and the path fades into quiet stonework to either side.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room194",
    "west":"/chapter/prologue/area/ruined/room/room137",
  ]);

}
