inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Cell";
  long_desc =
    "This cramped room has a narrow slit for light and a floor of cracked stone.\n"
    "Water stains run down the corners.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1158", "down",
    "domain/original/area/anshelm/room1160", "west",
  });

  set_light(1);
}
