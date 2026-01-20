inherit "room/room";

void create() {
  ::create();


  short_desc = "East End of Balin Road";
  long_desc = "East End of Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room664", "west",
    "domain/original/area/island/room666", "south",
  });

  set_light(1);
}
