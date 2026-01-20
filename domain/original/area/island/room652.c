inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room653", "west",
    "domain/original/area/island/room650", "east",
    "domain/original/area/island/room654", "north",
  });

  set_light(1);
}
