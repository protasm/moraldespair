inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Suite";
  long_desc = "A suite of rooms lies empty beyond a carved doorway. Dust lies in drifts where\nrugs once lay.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room921",
  ]);

  set_light(1);
}
