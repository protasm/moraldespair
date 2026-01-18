inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ink Room";
  long_desc = "The room is silent under a crust of paper dust, with broken rollers and a sagging frame. Ink stains still darken the boards, and warped trays rot in the damp.";
  dest_dir = ({
    "domain/original/area/vesla/room410", "east",
    "domain/original/area/vesla/room123", "south",
  });
}
