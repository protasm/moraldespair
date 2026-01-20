inherit "room/room";

void create() {
  ::create();


  short_desc = "A desert plain";
  long_desc = "A desert plain.\n";
  dest_dir = ({
    "domain/original/area/island/room628", "west",
    "domain/original/area/island/room630", "north",
  });

  set_light(1);
}
