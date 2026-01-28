inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Snowy Vault";
  long_desc = "Snow has drifted into a hollow chamber, piled in soft ridges. Bare rock shows\nthrough where the wind has scoured.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room348",
  ]);

  set_light(1);
}
