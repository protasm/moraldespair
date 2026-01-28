inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ink Room";
  long_desc = "The room is silent under a crust of paper dust, with broken rollers and a sagging frame. Ink stains still darken the boards, and warped trays rot in the damp.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room410",
    "south":"/chapter/prologue/area/ruined/room/room123",
  ]);

}
