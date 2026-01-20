inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "High Lookout";
  long_desc = "This lofty chamber opens to the wind, its outer wall cracked and partly fallen away. A ring of worn stone at the edge hints at a place of watch and signal.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room763", "northeast",
  });
}
