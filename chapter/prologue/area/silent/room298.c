inherit "room/room";

void create() {
  ::create();

  short_desc = "Crumbling Hall";
  long_desc = "A broad civic hall slumps behind a fallen portico. Its doors gape open onto\ndust and broken benches.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room291", "north",
  });

  set_light(1);
}
