inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Room";
  long_desc =
    "A small chamber holds a cracked basin and a warped doorway. The walls are\n"
    "stained by long-dry smoke.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1142", "west",
  });

  set_light(1);
}
