inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern Chamber";
  long_desc = "Eastern Chamber.\n";
  dest_dir = ({
    "domain/original/area/island/room672", "east",
    "domain/original/area/island/room714", "west",
  });

  set_light(1);
}
