inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Stilled Hall";
  long_desc = "A low hall stretches empty, its floor cold and bare.\n"
              + "Plaster peels from the walls in thin curls, and silence\n"
              + "gathers in corners.\n";
  dest_dir = ({
    "domain/original/area/vesla/room223", "west",
    "domain/original/area/vesla/room221", "east",
    "domain/original/area/vesla/room119", "north",
  });
}
