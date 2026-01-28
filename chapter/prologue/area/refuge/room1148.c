inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "East Steps";
  long_desc =
    "Stone steps climb within the eastern tower, their edges worn thin. A trickle\n"
    "of water runs down one wall.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1149",
  ]);

  set_light(1);
}
