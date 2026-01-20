inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Avenue";
  long_desc =
    "The avenue is paved in broad stones worn smooth by time. A row of bent iron\n"
    "lamps leans over the gutter.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1189", "east",
    "chapter/prologue/area/anshelm/room1187", "west",
  });

  set_light(1);
}
