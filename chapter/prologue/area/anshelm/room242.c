inherit "room/room";

void create() {
  ::create();

  short_desc = "Inner Gate";
  long_desc =
    "A second gate rises ahead, its guardwalk broken and open to the sky. Weed-\n"
    "choked steps lead through the arch.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room241", "south",
    "chapter/prologue/area/anshelm/room243", "north",
  });

  set_light(1);
}
