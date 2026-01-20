inherit "room/room";

void create() {
  ::create();


  short_desc = "Seed Shop";
  long_desc = "Seed Shop.\n";
  dest_dir = ({
    "domain/original/area/island/room661", "north",
  });

  set_light(1);
}
