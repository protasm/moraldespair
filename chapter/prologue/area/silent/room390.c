inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sagging Shed";
  long_desc = "A low structure of rough boards leans at a tired angle. Its roof has caved in\nalong one side.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room389", "west",
    "chapter/prologue/area/silent/room391", "east",
    "chapter/prologue/area/silent/room904", "south",
  });
}
