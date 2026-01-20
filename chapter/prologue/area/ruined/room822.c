inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Civic Hall";
  long_desc = "Broad steps lead to a hall of cracked stone, where dust lies in deep drifts. A splintered dais and toppled benches suggest old gatherings, now muted by rot and mildew.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room156", "east",
    "chapter/prologue/area/ruined/room831", "up",
  });
}
