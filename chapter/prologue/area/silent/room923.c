inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Brewery";
  long_desc = "Large vats sit rusted in a cool chamber. The floor is sticky with old spills\nand mold.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room920", "east",
  });

  set_light(1);
}
