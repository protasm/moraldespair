inherit "room/room";

void create() {
  ::create();


  short_desc = "Elderoak's Quarters";
  long_desc = "Elderoak's Quarters.\n";
  dest_dir = ({
    "domain/original/area/island/room632", "east",
  });

  set_light(1);
}
