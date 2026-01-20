inherit "room/room";

void create() {
  ::create();


  short_desc = "Ruins";
  long_desc = "Ruins.\n";
  dest_dir = ({
    "domain/original/area/island/room627", "east",
    "domain/original/area/island/room606", "west",
  });

  set_light(1);
}
