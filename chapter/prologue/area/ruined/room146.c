inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "Flat stones lie loose underfoot, some tipped into a shallow rut. A broken lintel rests against a wall, half buried in grit.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room845",
      "west":"/chapter/prologue/area/ruined/room145",
      "east":"/chapter/prologue/area/ruined/room147",
      "north":"/chapter/prologue/area/ruined/room842",
    ]);

  set_light(1);
}
