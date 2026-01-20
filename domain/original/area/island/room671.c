inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple Shop";
  long_desc = "Temple Shop.\n";
  dest_dir = ({
    "domain/original/area/island/room672", "west",
    "domain/original/area/island/room663", "south",
  });

  set_light(1);
}
