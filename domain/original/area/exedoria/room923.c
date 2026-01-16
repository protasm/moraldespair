inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Brewery";
  long_desc = "Large vats sit rusted in a cool chamber. The floor is sticky with old spills\nand mold.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room920", "east",
  });
}
