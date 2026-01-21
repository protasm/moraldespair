inherit "room/room";

void create() {
  ::create();

  short_desc = "Vast Foyer";
  long_desc = "A high entry hall opens beneath a cracked vault. Dust lies deep where\nfootsteps once echoed.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room348",
    "east":"/chapter/prologue/area/silent/room347",
    "north":"/chapter/prologue/area/silent/room345",
  ]);

  set_light(1);
}
