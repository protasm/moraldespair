inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Numb Hall";
  long_desc = "A low hall sits empty, its stone floor cold and bare. Faded\n"
              + "trim peels from the walls, and the quiet is deep.\n";
  dest_dir = ({
    "domain/original/area/vesla/room223", "west",
    "domain/original/area/vesla/room221", "east",
    "domain/original/area/vesla/room119", "north",
  });
}
