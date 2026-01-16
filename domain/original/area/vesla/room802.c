inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Crooked Cut";
  long_desc = "This crooked alley is lined with cracked stone and peeling plaster\n"
    "that smells of old damp. A broken curb and shallow ruts hint at\n"
    "steady foot and cart traffic.\n";
  dest_dir = ({
    "domain/original/area/vesla/room805", "south",
    "domain/original/area/vesla/room803", "west",
    "domain/original/area/vesla/room799", "east",
    "domain/original/area/vesla/room807", "north",
  });
}
