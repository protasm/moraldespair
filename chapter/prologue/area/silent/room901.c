inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Office";
  long_desc = "A modest office holds a cracked desk and empty shelves. The window shutters\nhang loose on their hinges.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room900", "south",
  });

  set_light(1);
}
