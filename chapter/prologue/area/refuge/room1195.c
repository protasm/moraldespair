inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Bridge";
  long_desc =
    "The drawbridge sags at its chains, its planks split and dark. A dry moat lies\n"
    "beneath, scattered with fallen stone.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room255",
    "west" : "/chapter/prologue/area/refuge/room1196",
  ]);

  set_light(1);
}
