inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Passage";
  long_desc =
    "A narrow passage runs along the inner wall, lit by a broken slit. Fine grit\n"
    "lies under fallen plaster.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1151", "up",
    "domain/original/area/anshelm/room1145", "west",
  });

  set_light(1);
}
