inherit "room/room";

void create() {
  ::create();

  short_desc = "Overgrown Lawn";
  long_desc = "What was once a tended lawn is now a mat of tall grass. Stone borders still\ntrace its careful shape.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room346", "south",
    "chapter/prologue/area/silent/room344", "north",
  });

  set_light(1);
}
