inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Chamber";
  long_desc = "This chamber holds a chill that lingers year round. Frost clings to the stone\nin thin, pale sheets.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room346",
  ]);

  set_light(1);
}
