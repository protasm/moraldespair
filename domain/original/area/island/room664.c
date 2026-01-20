inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room667", "south",
    "domain/original/area/island/room663", "west",
    "domain/original/area/island/room665", "east",
    "domain/original/area/island/room668", "north",
  });

  set_light(1);
}
