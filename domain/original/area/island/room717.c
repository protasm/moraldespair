inherit "room/room";

void create() {
  ::create();


  short_desc = "Poison Shop";
  long_desc = "Poison Shop.\n";
  dest_dir = ({
    "domain/original/area/island/room635", "north",
  });

  set_light(1);
}
