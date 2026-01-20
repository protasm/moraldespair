inherit "room/room";

void create() {
  ::create();

  short_desc = "East Steps";
  long_desc =
    "Stone steps climb within the eastern tower, their edges worn thin. A trickle\n"
    "of water runs down one wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1149", "down",
  });

  set_light(1);
}
