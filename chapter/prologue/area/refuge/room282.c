inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Narrow Gap";
  long_desc =
    "A tight passage squeezes between two leaning walls. The stone here is smooth\n"
    "with wear and damp.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room265",
  ]);

  set_light(1);
}
