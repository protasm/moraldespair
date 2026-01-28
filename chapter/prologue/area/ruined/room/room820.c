inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Ward";
  long_desc = "Stone tables stand in a damp row, their surfaces stained and slick with mildew. Shelves of dried herbs have collapsed into dust, and a cracked basin gathers stale water beneath a ceiling gone soft with rot.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room839",
    "east":"/chapter/prologue/area/ruined/room/room153",
    "north":"/chapter/prologue/area/ruined/room/room838",
  ]);

}
