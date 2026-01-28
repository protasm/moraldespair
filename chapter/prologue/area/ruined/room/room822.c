inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Civic Hall";
  long_desc = "Broad steps lead to a hall of cracked stone, where dust lies in deep drifts. A splintered dais and toppled benches suggest old gatherings, now muted by rot and mildew.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room156",
    "up":"/chapter/prologue/area/ruined/room/room831",
  ]);

}
