inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ({
    "domain/original/area/island/room708", "south",
  });

  set_light(1);
}
