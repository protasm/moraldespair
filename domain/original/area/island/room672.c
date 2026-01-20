inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple Plaza";
  long_desc = "Temple Plaza.\n";
  dest_dir = ({
    "domain/original/area/island/room715", "west",
    "domain/original/area/island/room671", "east",
    "domain/original/area/island/room662", "south",
  });

  set_light(1);
}
