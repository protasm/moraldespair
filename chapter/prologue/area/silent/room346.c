inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Vast Foyer";
  long_desc = "A high entry hall opens beneath a cracked vault. Dust lies deep where\nfootsteps once echoed.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room348", "west",
    "chapter/prologue/area/silent/room347", "east",
    "chapter/prologue/area/silent/room345", "north",
  });
}
