inherit "room/room";

void create() {
  ::create();


  short_desc = "RIIS";
  long_desc = "RIIS.\n";
  dest_dir = ({
    "domain/original/area/island/room687", "down",
    "domain/original/area/island/room677", "south",
  });

  set_light(1);
}
