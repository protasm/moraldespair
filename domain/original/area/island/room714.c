inherit "room/room";

void create() {
  ::create();


  short_desc = "Central Chamber";
  long_desc = "Central Chamber.\n";
  dest_dir = ({
    "domain/original/area/island/room715", "east",
    "domain/original/area/island/room713", "west",
  });

  set_light(1);
}
