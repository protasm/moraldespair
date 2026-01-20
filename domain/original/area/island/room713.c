inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple";
  long_desc = "Temple.\n";
  dest_dir = ({
    "domain/original/area/island/room611", "west",
    "domain/original/area/island/room714", "east",
    "domain/original/area/island/room716", "north",
  });

  set_light(1);
}
