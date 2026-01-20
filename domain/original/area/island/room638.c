inherit "room/room";

void create() {
  ::create();


  short_desc = "Tunnel Under Canal";
  long_desc = "Tunnel Under Canal.\n";
  dest_dir = ({
    "domain/original/area/island/room637", "east",
    "domain/original/area/island/room639", "west",
  });

  set_light(1);
}
