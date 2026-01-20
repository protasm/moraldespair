inherit "room/room";

void create() {
  ::create();


  short_desc = "Bedchamber";
  long_desc = "Bedchamber.\n";
  dest_dir = ({
    "domain/original/area/island/room701", "east",
    "domain/original/area/island/room699", "west",
  });

  set_light(1);
}
