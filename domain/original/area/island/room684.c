inherit "room/room";

void create() {
  ::create();


  short_desc = "Hallway";
  long_desc = "Hallway.\n";
  dest_dir = ({
    "domain/original/area/island/room685", "south",
    "domain/original/area/island/room679", "north",
  });

  set_light(1);
}
