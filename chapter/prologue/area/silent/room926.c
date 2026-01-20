inherit "room/room";

void create() {
  ::create();

  short_desc = "Windmill Base";
  long_desc = "The base of a windmill stands open to the wind, its beams creaking. Grain dust\nhas long settled into the floor.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room929", "up",
    "chapter/prologue/area/silent/room927", "west",
    "chapter/prologue/area/silent/room928", "east",
    "chapter/prologue/area/silent/room319", "south",
  });

  set_light(1);
}
