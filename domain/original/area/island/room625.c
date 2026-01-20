inherit "room/room";

void create() {
  ::create();


  short_desc = "The base of a waterfall";
  long_desc = "The base of a waterfall.\n";
  dest_dir = ({
    "domain/original/area/island/room624", "east",
  });

  set_light(1);
}
