inherit "room/room";

void create() {
  ::create();

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward a wider street, its stones chipped and uneven. A sagging\n"
    "lintel hangs over a dark doorway.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room284",
  ]);

  set_light(1);
}
