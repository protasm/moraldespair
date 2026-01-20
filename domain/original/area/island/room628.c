inherit "room/room";

void create() {
  ::create();


  short_desc = "A valley between two large dunes";
  long_desc = "A valley between two large dunes.\n";
  dest_dir = ({
    "domain/original/area/island/room629", "east",
    "domain/original/area/island/room607", "west",
  });

  set_light(1);
}
