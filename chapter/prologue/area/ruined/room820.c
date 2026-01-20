inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Ward";
  long_desc = "Stone tables stand in a damp row, their surfaces stained and slick with mildew. Shelves of dried herbs have collapsed into dust, and a cracked basin gathers stale water beneath a ceiling gone soft with rot.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room839", "west",
    "chapter/prologue/area/ruined/room153", "east",
    "chapter/prologue/area/ruined/room838", "north",
  });
}
