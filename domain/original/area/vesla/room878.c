inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Stall";
  long_desc = "The vacant room is quiet, its plaster flaking and the air damp. Rotten joists\n"
              + "and old fittings hint at a stall once meant for lease.\n";
  dest_dir = ({
    "domain/original/area/vesla/room127", "south",
  });
}
