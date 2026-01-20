inherit "room/room";

void create() {
  ::create();

  short_desc = "Long Street";
  long_desc =
    "The road runs straight between crumbling barracks. Wind has pushed leaves into\n"
    "slow drifts.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room271", "west",
    "domain/original/area/anshelm/room269", "east",
    "domain/original/area/anshelm/room1199", "south",
  });

  set_light(1);
}
