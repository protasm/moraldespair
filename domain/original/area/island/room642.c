inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room643", "west",
    "domain/original/area/island/room641", "south",
  });

  set_light(1);
}
