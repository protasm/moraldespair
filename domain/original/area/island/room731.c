inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern slave bazaar";
  long_desc = "Eastern slave bazaar.\n";
  dest_dir = ({
    "domain/original/area/island/room732", "west",
    "domain/original/area/island/room730", "north",
  });

  set_light(1);
}
