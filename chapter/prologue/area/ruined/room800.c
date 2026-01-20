inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Rot Cut";
  long_desc = "The alley widens slightly, filled with rotting boards and a soft bed of dust. A leaning beam and iron staple suggest a former stall or screen.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room799", "west",
    "chapter/prologue/area/ruined/room801", "east",
    "chapter/prologue/area/ruined/room806", "north",
  });
}
