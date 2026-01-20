inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room661", "west",
    "domain/original/area/island/room663", "east",
    "domain/original/area/island/room672", "north",
  });

  set_light(1);
}
