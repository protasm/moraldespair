inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Silent Court";
  long_desc = "Silence hangs in this inner court where weeds thread between cracked\n"
    "stones. A low step and a cracked curb trace where carts once\n"
    "turned.\n";
  dest_dir = ({
    "domain/original/area/vesla/room757", "west",
    "domain/original/area/vesla/room759", "south",
    "domain/original/area/vesla/room766", "northwest",
    "domain/original/area/vesla/room765", "north",
  });
}
