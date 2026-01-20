inherit "room/room";

void create() {
  ::create();

  short_desc = "Trade Office";
  long_desc = "A small office holds a counting table and empty shelves. The shutters are\ncracked and hang ajar.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room916", "north",
  });

  set_light(1);
}
