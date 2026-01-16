inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Rot Cut";
  long_desc = "The alley widens slightly, filled with rotting boards and a soft bed\n"
    "of dust. A leaning beam and iron staple suggest a former stall or\n"
    "screen.\n";
  dest_dir = ({
    "domain/original/area/vesla/room799", "west",
    "domain/original/area/vesla/room801", "east",
    "domain/original/area/vesla/room806", "north",
  });
}
