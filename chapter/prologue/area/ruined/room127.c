inherit "room/room";

void create() {
  ::create();

  short_desc = "Old City Gate";
  long_desc = "A battered gateway stands between worn walls, its lintel cracked and sagging. Dust gathers in the deep grooves of the threshold, and no sound follows the road beyond.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room128", "west",
    "chapter/prologue/area/ruined/room126", "east",
    "chapter/prologue/area/ruined/room878", "north",
  });

  set_light(1);
}
