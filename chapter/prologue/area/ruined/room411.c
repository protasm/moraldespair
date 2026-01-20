inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ink Room";
  long_desc = "The room is silent under a crust of paper dust, with broken rollers and a sagging frame. Ink stains still darken the boards, and warped trays rot in the damp.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room410", "east",
    "chapter/prologue/area/ruined/room123", "south",
  });
}
