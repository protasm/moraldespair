inherit "room/room";

void create() {
  ::create();

    short_desc = "Wall Road West";
    long_desc = "The road ends against the inner wall, where the paving breaks into rubble and a shallow drift of sand. The wall looms close, its lower stones stained dark by old runoff and moss.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room171",
      "west":"/chapter/prologue/area/ruined/room168",
    ]);

  set_light(1);
}
