inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Suite";
  long_desc = "A suite of rooms lies empty beyond a carved doorway. Dust lies in drifts where\nrugs once lay.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room921", "south",
  });

  set_light(1);
}
