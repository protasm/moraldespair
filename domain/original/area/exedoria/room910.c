inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gravel Path";
  long_desc = "Loose gravel crunches along a narrow path. The ground beside it is soft with\nmoss.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room604", "southeast",
    "domain/original/area/exedoria/room908", "northeast",
  });
}
