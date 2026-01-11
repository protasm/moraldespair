inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Ward";
  long_desc = "Stone tables stand in a damp row, their surfaces stained and slick with mildew.\n"
              + "Shelves of dried herbs have collapsed into dust, and a cracked basin gathers\n"
              + "stale water beneath a ceiling gone soft with rot.\n";
  dest_dir = ({
    "domain/original/area/vesla/room839", "west",
    "domain/original/area/vesla/room153", "east",
    "domain/original/area/vesla/room838", "north",
  });
}
