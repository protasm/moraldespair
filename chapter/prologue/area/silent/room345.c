inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Overgrown Lawn";
  long_desc = "What was once a tended lawn is now a mat of tall grass. Stone borders still\ntrace its careful shape.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room346",
    "north":"/chapter/prologue/area/silent/room344",
  ]);

  set_light(1);
}
