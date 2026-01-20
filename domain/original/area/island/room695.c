inherit "room/room";

void create() {
  ::create();


  short_desc = "Guard Post";
  long_desc = "Guard Post.\n";
  dest_dir = ({
    "domain/original/area/island/room694", "north",
  });

  set_light(1);
}
