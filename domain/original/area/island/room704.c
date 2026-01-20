inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ({
    "domain/original/area/island/room705", "south",
    "domain/original/area/island/room706", "east",
    "domain/original/area/island/room703", "north",
  });

  set_light(1);
}
