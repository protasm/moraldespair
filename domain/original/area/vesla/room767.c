inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Echo Court";
  long_desc = "The court here is narrower, hemmed by rough walls and roofless\n"
    "alcoves. A rusted bracket and a shallow socket in the stone hint at\n"
    "a former lantern line.\n";
  dest_dir = ({
    "domain/original/area/vesla/room768", "east",
    "domain/original/area/vesla/room765", "southeast",
    "domain/original/area/vesla/room766", "south",
  });
}
