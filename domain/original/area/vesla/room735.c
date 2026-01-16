inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Faded Plot";
  long_desc = "A sunken patch of earth lies between low foundations, its surface matted\n"
              "with weed, dust, and black mildew. Rotted post stubs and a bent iron\n"
              "bracket linger at the edge, with scattered planks and a worn stone lip\n"
              "hinting at some former frontage.\n";
  dest_dir = ({
    "domain/original/area/vesla/room172", "west",
  });
}
