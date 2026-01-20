inherit "room/room";

void create() {
  ::create();


  short_desc = "Rhian's Potion Shop";
  long_desc = "Rhian's Potion Shop.\n";
  dest_dir = ({
    "domain/original/area/island/room615", "east",
  });

  set_light(1);
}
