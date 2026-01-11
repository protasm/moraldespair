inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Stall";
  long_desc = "The vacant room is quiet, its plaster flaking and the\n"
              + "air damp. Rotten joists and old fittings hint at a\n"
              + "stall once meant for lease.\n";
  dest_dir = ({
    "domain/original/area/vesla/room127", "south",
  });
}
