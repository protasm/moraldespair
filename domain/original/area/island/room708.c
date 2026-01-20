inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ({
    "domain/original/area/island/room702", "west",
    "domain/original/area/island/room707", "south",
    "domain/original/area/island/room709", "north",
  });

  set_light(1);
}
