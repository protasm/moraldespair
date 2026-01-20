inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room722", "southwest",
    "domain/original/area/island/room635", "east",
    "domain/original/area/island/room721", "southeast",
    "domain/original/area/island/room637", "west",
  });

  set_light(1);
}
