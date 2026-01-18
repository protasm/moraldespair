inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Gray Court";
  long_desc = "Gray dust coats the paving, and fragments of plaster lie in soft ridges. A broad, straight run of stones implies an old processional path through the ward.";
  dest_dir = ({
    "domain/original/area/vesla/room766", "southwest",
    "domain/original/area/vesla/room767", "west",
    "domain/original/area/vesla/room769", "east",
    "domain/original/area/vesla/room765", "south",
  });
}
