inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Intersection of Basalt Avenue and Rapier Way";
  long_desc = "Two worn streets cross on uneven basalt, their corners softened by age and grit.\n"
              + "The stones are cracked and slumped, leaving shallow puddles and windblown grit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room138", "south",
    "domain/original/area/vesla/room193", "east",
    "domain/original/area/vesla/room136", "north",
  });
}
