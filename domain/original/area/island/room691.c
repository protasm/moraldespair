inherit "room/room";

void create() {
  ::create();


  short_desc = "Power System Generator";
  long_desc = "Power System Generator.\n";
  dest_dir = ({
    "domain/original/area/island/room692", "east",
    "domain/original/area/island/room618", "west",
  });

  set_light(1);
}
