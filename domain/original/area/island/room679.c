inherit "room/room";

void create() {
  ::create();


  short_desc = "Foyer";
  long_desc = "Foyer.\n";
  dest_dir = ({
    "domain/original/area/island/room684", "south",
    "domain/original/area/island/room678", "east",
    "domain/original/area/island/room680", "north",
  });

  set_light(1);
}
