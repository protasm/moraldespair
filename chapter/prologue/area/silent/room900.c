inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Study Hall";
  long_desc = "Rows of benches face a high dais in a broad hall. The floor is scuffed by\nlong-quiet feet.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room899",
    "north":"/chapter/prologue/area/silent/room901",
  ]);

  set_light(1);
}
