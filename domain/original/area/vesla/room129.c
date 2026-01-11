inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Ruins";
  long_desc = "Westroad runs between low stone shells, their upper courses missing. Fallen\n"
              + "blocks lie in the ruts, and a thin growth of grass softens the roadway.\n";
  dest_dir = ({
    "domain/original/area/vesla/room130", "west",
    "domain/original/area/vesla/room128", "east",
    "domain/original/area/vesla/room419", "south",
  });
}
