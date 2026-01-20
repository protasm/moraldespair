inherit "room/room";

void create() {
  ::create();


  short_desc = "Western District";
  long_desc = "Western District.\n";
  dest_dir = ({
    "domain/original/area/island/room728", "south",
    "domain/original/area/island/room726", "north",
  });

  set_light(1);
}
