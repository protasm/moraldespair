inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Cross";
  long_desc = "Two worn streets cross in a patch of sunken stone. The corners are choked with\nrubble from nearby walls.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room296",
  ]);

  set_light(1);
}
