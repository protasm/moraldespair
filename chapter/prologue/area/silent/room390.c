inherit "room/room";

void create() {
  ::create();

  short_desc = "Sagging Shed";
  long_desc = "A low structure of rough boards leans at a tired angle. Its roof has caved in\nalong one side.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room389",
    "east":"/chapter/prologue/area/silent/room391",
    "south":"/chapter/prologue/area/silent/room904",
  ]);

  set_light(1);
}
