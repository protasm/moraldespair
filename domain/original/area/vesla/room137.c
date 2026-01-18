inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Crossing";
  long_desc = "Two worn streets cross on uneven basalt, their corners softened by age and grit. The stones are cracked and slumped, leaving shallow puddles and windblown grit.";
  dest_dir = ({
    "domain/original/area/vesla/room138", "south",
    "domain/original/area/vesla/room193", "east",
    "domain/original/area/vesla/room136", "north",
  });
}

