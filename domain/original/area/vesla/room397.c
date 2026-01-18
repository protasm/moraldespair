inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sooted Study";
  long_desc = "Soot stains the stone around a slumped hearth, and chalky rings fade on the floor beneath a crust of dust. Shelves of warped wood hold scattered vials and stiffened pages, their ink bled by damp and mildew.";
  dest_dir = ({
    "domain/original/area/vesla/room398", "east",
    "domain/original/area/vesla/room206", "south",
  });
}
