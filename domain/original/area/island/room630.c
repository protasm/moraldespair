inherit "room/room";

void create() {
  ::create();


  short_desc = "A dead end";
  long_desc = "A dead end.\n";
  dest_dir = ({
    "domain/original/area/island/room629", "south",
  });

  set_light(1);
}
