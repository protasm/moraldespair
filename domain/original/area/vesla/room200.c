inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cracked Crossing";
  long_desc = "Two worn ways meet in a sagging cross, their seams packed with damp grit and tiny weeds. The center stones are polished hollow by long-forgotten traffic, with rust flakes gathered in the low joints.";
  dest_dir = ({
    "domain/original/area/vesla/room201", "west",
    "domain/original/area/vesla/room199", "north",
  });
}
