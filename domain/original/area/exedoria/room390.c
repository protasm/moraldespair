inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sagging Shed";
  long_desc = "A low structure of rough boards leans at a tired angle. Its roof has caved in\nalong one side.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room389", "west",
    "domain/original/area/exedoria/room391", "east",
    "domain/original/area/exedoria/room904", "south",
  });
}
