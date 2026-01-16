inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Overgrown Lawn";
  long_desc = "What was once a tended lawn is now a mat of tall grass. Stone borders still\ntrace its careful shape.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room346", "south",
    "domain/original/area/exedoria/room344", "north",
  });
}
