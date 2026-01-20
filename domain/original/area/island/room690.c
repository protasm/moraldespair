inherit "room/room";

void create() {
  ::create();


  short_desc = "Entrance to the Hall of Records";
  long_desc = "Entrance to the Hall of Records.\n";
  dest_dir = ({
    "domain/original/area/island/room617", "east",
  });

  set_light(1);
}
