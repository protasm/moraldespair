inherit "room/room";

void create() {
  ::create();

  short_desc = "Nailed Notices";
  long_desc = "A warped board is riddled with rusted nails, silent under dust and mildew. Faded names and tally marks sit in rot, hinting at claims once posted in a long-quiet hall.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room219",
  ]);

  set_light(1);
}
