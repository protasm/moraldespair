inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Bridge";
  long_desc = "A heavy bridge spans a shallow moat now filled with reed and mud. Chains hang\nslack where the lift once rose.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room310",
    "west":"/chapter/prologue/area/silent/room356",
  ]);

  set_light(1);
}
