inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Trade Hall";
  long_desc = "The chamber is wide and bare, its tiled floor split by damp and weeds. A set of warped benches faces a crumbling stand, with rotted placards scattered in the dust.";
  dest_dir = ({
    "domain/original/area/vesla/room831", "east",
  });
}
