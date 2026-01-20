inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Office";
  long_desc = "A modest office holds a cracked desk and empty shelves. The window shutters\nhang loose on their hinges.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room900", "south",
  });
}
