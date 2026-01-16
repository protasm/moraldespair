inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "High Lookout";
  long_desc = "This lofty chamber opens to the wind, its outer wall cracked and\n"
    "partly fallen away. A ring of worn stone at the edge hints at a\n"
    "place of watch and signal.\n";
  dest_dir = ({
    "domain/original/area/vesla/room763", "northeast",
  });
}
