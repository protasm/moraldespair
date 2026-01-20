inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Cut";
  long_desc = "A tight passage runs between leaning walls, choked with damp rot and black mildew. Broken drains and sagging lintels suggest a service way once kept clear, now sealed in silence.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room411",
    "south":"/chapter/prologue/area/ruined/room122",
    "north":"/chapter/prologue/area/ruined/room792",
  ]);

  set_light(1);
}
