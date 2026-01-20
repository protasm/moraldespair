inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "The paving here is split by roots, forming a jagged seam. A toppled arch stone blocks part of the way.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room408",
      "south":"/chapter/prologue/area/ruined/room216",
      "north":"/chapter/prologue/area/ruined/room218",
    ]);

  set_light(1);
}
