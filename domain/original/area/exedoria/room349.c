inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Snowy Vault";
  long_desc = "Snow has drifted into a hollow chamber, piled in soft ridges. Bare rock shows\nthrough where the wind has scoured.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room348", "north",
  });
}
