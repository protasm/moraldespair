inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Upper Room";
  long_desc =
    "A small chamber holds a cracked basin and a warped doorway. The walls are\n"
    "stained by long-dry smoke.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1142",
  ]);

  set_light(1);
}
