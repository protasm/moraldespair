inherit "room/room";

void create() {
  ::create();


  short_desc = "Western District";
  long_desc = "Western District.\n";
  dest_dir = ({
    "domain/original/area/island/room725", "east",
    "domain/original/area/island/room727", "south",
  });

  set_light(1);
}
