inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "Cracked paving leads past a row of empty doorways. Grass pushes up where the\njoints have widened.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room897", "south",
    "chapter/prologue/area/silent/room528", "north",
  });

  set_light(1);
}
