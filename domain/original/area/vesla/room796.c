inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Blind Cut";
  long_desc = "This tight passage ends in rubble, its floor sunk with dust and\n"
    "mortar. A bricked arch and iron pins suggest a once-used service\n"
    "door.\n";
  dest_dir = ({
    "domain/original/area/vesla/room814", "south",
    "domain/original/area/vesla/room795", "west",
    "domain/original/area/vesla/room231", "east",
    "domain/original/area/vesla/room961", "north",
  });
}
