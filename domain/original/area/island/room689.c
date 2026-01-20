inherit "room/room";

void create() {
  ::create();


  short_desc = "Alchemist Shop";
  long_desc = "Alchemist Shop.\n";
  dest_dir = ({
    "domain/original/area/island/room616", "west",
  });

  set_light(1);
}
