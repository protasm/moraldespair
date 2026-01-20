inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Blind Cut";
  long_desc = "This tight passage ends in rubble, its floor sunk with dust and mortar. A bricked arch and iron pins suggest a once-used service door.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room814", "south",
    "chapter/prologue/area/ruined/room795", "west",
    "chapter/prologue/area/ruined/room231", "east",
    "chapter/prologue/area/ruined/room961", "north",
  });
}
