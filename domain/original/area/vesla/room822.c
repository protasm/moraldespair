inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Civic Hall";
  long_desc = "Broad steps lead to a hall of cracked stone, where dust lies in deep drifts. A\n"
              + "splintered dais and toppled benches suggest old gatherings, now muted by rot and\n"
              + "mildew.\n";
  dest_dir = ({
    "domain/original/area/vesla/room156", "east",
    "domain/original/area/vesla/room831", "up",
  });
}
