inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Office";
  long_desc = "A heavy chair sits askew behind a broad desk, both softened by rot and damp. Dust mounds around a broken seal press, and mildew climbs the cracked plaster.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room833",
  ]);

  set_light(1);
}
