inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room647", "south",
    "domain/original/area/island/room642", "east",
    "domain/original/area/island/room644", "north",
  });

  set_light(1);
}
