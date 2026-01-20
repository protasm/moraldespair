inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room657", "south",
    "domain/original/area/island/room639", "east",
    "domain/original/area/island/room641", "north",
  });

  set_light(1);
}
