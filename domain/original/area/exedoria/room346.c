inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Vast Foyer";
  long_desc = "A high entry hall opens beneath a cracked vault. Dust lies deep where\nfootsteps once echoed.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room348", "west",
    "domain/original/area/exedoria/room347", "east",
    "domain/original/area/exedoria/room345", "north",
  });
}
