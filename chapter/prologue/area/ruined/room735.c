inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Plot";
  long_desc = "A sunken patch of earth lies between low foundations, its surface matted with weed, dust, and black mildew. Rotted post stubs and a bent iron bracket linger at the edge, with scattered planks and a worn stone lip hinting at some former frontage.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room172", "west",
  });

  set_light(1);
}
