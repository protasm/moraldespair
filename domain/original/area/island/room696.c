inherit "room/room";

void create() {
  ::create();


  short_desc = "North Corridor";
  long_desc = "North Corridor.\n";
  dest_dir = ({
    "domain/original/area/island/room693", "south",
    "domain/original/area/island/room697", "north",
  });

  set_light(1);
}
