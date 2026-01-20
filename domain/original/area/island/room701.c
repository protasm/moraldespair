inherit "room/room";

void create() {
  ::create();


  short_desc = "Entryway";
  long_desc = "Entryway.\n";
  dest_dir = ({
    "domain/original/area/island/room700", "west",
    "domain/original/area/island/room702", "south",
  });

  set_light(1);
}
