inherit "room/room";

void create() {
  ::create();

  short_desc = "Cinder Row";
  long_desc = "Charcoal streaks still mark the stones, now silent and weatherworn beneath lichen and mildew. Collapsed rafters and dusted crockery sit in rot, hinting at a small shop long abandoned.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room845", "west",
    "chapter/prologue/area/ruined/room147", "north",
  });

  set_light(1);
}
