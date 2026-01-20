inherit "room/room";

void create() {
  ::create();

  short_desc = "East Roof";
  long_desc =
    "The roof of the eastern spire is open to the weather, its parapet broken. A\n"
    "lone flagpole lies across the stones.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1151", "down",
  });

  set_light(1);
}
