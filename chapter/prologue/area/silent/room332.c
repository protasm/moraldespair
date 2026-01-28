inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dusty Taproom";
  long_desc = "A low room of tables and a cracked bar lies silent. Dull glass and dry spills\nstain the floor.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room331",
  ]);

  set_light(1);
}
