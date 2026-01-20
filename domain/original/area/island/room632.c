inherit "room/room";

void create() {
  ::create();


  short_desc = "Armoury";
  long_desc = "Armoury.\n";
  dest_dir = ({
    "domain/original/area/island/room631", "east",
    "domain/original/area/island/room633", "west",
  });

  set_light(1);
}
