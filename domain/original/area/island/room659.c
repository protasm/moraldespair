inherit "room/room";

void create() {
  ::create();


  short_desc = "Bedroom:";
  long_desc = "Bedroom:.\n";
  dest_dir = ({
    "domain/original/area/island/room657", "east",
  });

  set_light(1);
}
