inherit "room/room";

void create() {
  ::create();

  short_desc = "Shuttered Front";
  long_desc = "A warped counter blocks the entry, silent under dust and mildew. Bare shelves and a torn awning sit in rot, hinting at trade long faded.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room199",
  ]);

  set_light(1);
}
