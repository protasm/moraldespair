inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ({
    "domain/original/area/island/room652", "west",
    "domain/original/area/island/room648", "south",
  });

  set_light(1);
}
