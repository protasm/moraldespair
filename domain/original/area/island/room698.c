inherit "room/room";

void create() {
  ::create();


  short_desc = "West Harem";
  long_desc = "West Harem.\n";
  dest_dir = ({
    "domain/original/area/island/room699", "east",
    "domain/original/area/island/room697", "west",
  });

  set_light(1);
}
