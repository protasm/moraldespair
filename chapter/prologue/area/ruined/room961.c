inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cask Room";
  long_desc = "The air is stale and damp, with broken casks split and rotting. A soot-stained hearth and a copper coil left to tarnish hint at spirits once drawn here.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room796", "south",
  });
}
