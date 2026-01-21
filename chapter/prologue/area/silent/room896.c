inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "Cracked paving leads past a row of empty doorways. Grass pushes up where the\njoints have widened.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room897",
    "north":"/chapter/prologue/area/silent/room528",
  ]);

  set_light(1);
}
