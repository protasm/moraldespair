inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Old Brewery";
  long_desc = "Large vats sit rusted in a cool chamber. The floor is sticky with old spills\nand mold.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room920",
  ]);

  set_light(1);
}
