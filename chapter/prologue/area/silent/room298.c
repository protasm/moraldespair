inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Crumbling Hall";
  long_desc = "A broad civic hall slumps behind a fallen portico. Its doors gape open onto\ndust and broken benches.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room291",
  ]);

  set_light(1);
}
