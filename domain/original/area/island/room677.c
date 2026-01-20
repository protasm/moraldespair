inherit "room/room";

void create() {
  ::create();


  short_desc = "Gate House";
  long_desc = "Gate House.\n";
  dest_dir = ({
    "domain/original/area/island/room676", "south",
    "domain/original/area/island/room614", "west",
    "domain/original/area/island/room693", "east",
    "domain/original/area/island/room686", "north",
  });

  set_light(1);
}
