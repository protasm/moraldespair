inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Salon";
  long_desc =
    "A quiet room holds a few toppled chairs and a cracked mosaic floor. The walls\n"
    "are stained with old smoke and damp.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1332", "south",
    "chapter/prologue/area/anshelm/room1329", "west",
    "chapter/prologue/area/anshelm/room1331", "east",
    "chapter/prologue/area/anshelm/room1333", "north",
  });

  set_light(1);
}
