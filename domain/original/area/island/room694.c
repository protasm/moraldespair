inherit "room/room";

void create() {
  ::create();


  short_desc = "South Corridor";
  long_desc = "South Corridor.\n";
  dest_dir = ({
    "domain/original/area/island/room695", "south",
    "domain/original/area/island/room693", "north",
  });

  set_light(1);
}
