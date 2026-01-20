inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Cross";
  long_desc = "Two worn streets cross in a patch of sunken stone. The corners are choked with\nrubble from nearby walls.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room296", "west",
  });

  set_light(1);
}
