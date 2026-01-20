inherit "room/room";

void create() {
  ::create();


  short_desc = "Gate House";
  long_desc = "Gate House.\n";
  dest_dir = ({
    "domain/original/area/island/room614", "east",
    "domain/original/area/island/room679", "west",
  });

  set_light(1);
}
