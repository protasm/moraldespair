inherit "room/room";

void create() {
  ::create();


  short_desc = "A guard house";
  long_desc = "A guard house.\n";
  dest_dir = ({
    "domain/original/area/island/room609", "west",
  });

  set_light(1);
}
