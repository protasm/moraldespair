inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Gravel Walk";
  long_desc = "A gravel path winds toward a distant, pale structure. Pebbles crunch in the\nwind where weeds have not taken hold.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room379",
    "west":"/chapter/prologue/area/silent/room371",
  ]);

  set_light(1);
}
