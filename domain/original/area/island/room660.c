inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room661", "east",
    "domain/original/area/island/room610", "west",
  });

  set_light(1);
}
