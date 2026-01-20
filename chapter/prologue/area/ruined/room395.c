inherit "room/room";

void create() {
  ::create();

  short_desc = "Turner's Bench";
  long_desc = "A cracked lathe stands in the corner, silent and ruined beneath dust and mildew. Spilled shavings and dulled tools sit in rot, hinting at careful turning left to waste.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room209", "south",
  });

  set_light(1);
}
