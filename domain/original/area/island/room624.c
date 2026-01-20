inherit "room/room";

void create() {
  ::create();


  short_desc = "East of the waterfall";
  long_desc = "East of the waterfall.\n";
  dest_dir = ({
    "domain/original/area/island/room623", "east",
    "domain/original/area/island/room625", "west",
  });

  set_light(1);
}
