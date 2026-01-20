inherit "room/room";

void create() {
  ::create();


  short_desc = "Western slave bazaar";
  long_desc = "Western slave bazaar.\n";
  dest_dir = ({
    "domain/original/area/island/room732", "east",
    "domain/original/area/island/room727", "north",
  });

  set_light(1);
}
