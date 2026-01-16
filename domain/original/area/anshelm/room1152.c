inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Roof";
  long_desc =
    "The roof of the eastern spire is open to the weather, its parapet broken. A\n"
    "lone flagpole lies across the stones.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1151", "down",
  });
}
