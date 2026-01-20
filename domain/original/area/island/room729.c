inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern District";
  long_desc = "Eastern District.\n";
  dest_dir = ({
    "domain/original/area/island/room725", "west",
    "domain/original/area/island/room730", "south",
  });

  set_light(1);
}
