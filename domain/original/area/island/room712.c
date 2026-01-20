inherit "room/room";

void create() {
  ::create();


  short_desc = "Hermit's Chamber";
  long_desc = "Hermit's Chamber.\n";
  dest_dir = ({
    "domain/original/area/island/room655", "east",
  });

  set_light(1);
}
