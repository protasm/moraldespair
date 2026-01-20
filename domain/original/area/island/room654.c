inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room652", "south",
    "domain/original/area/island/room655", "north",
  });

  set_light(1);
}
