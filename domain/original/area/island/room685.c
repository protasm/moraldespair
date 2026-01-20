inherit "room/room";

void create() {
  ::create();


  short_desc = "Lady Roland's Bedroom";
  long_desc = "Lady Roland's Bedroom.\n";
  dest_dir = ({
    "domain/original/area/island/room684", "north",
  });

  set_light(1);
}
