inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Trade Office";
  long_desc = "A small office holds a counting table and empty shelves. The shutters are\ncracked and hang ajar.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room916", "north",
  });
}
