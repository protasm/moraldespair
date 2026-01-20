inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern District";
  long_desc = "Eastern District.\n";
  dest_dir = ({
    "domain/original/area/island/room731", "south",
    "domain/original/area/island/room729", "north",
  });

  set_light(1);
}
