inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Scoured Plot";
  long_desc = "PHASE0: an empty lot for a player-owned business";
              "weed and grit, with dark dampness sinking into the edges.\n"
              "Rotted post stubs and a bent iron bracket mark where a sign once\n"
              "hung, while broken boards sink into the mud.\n";
  dest_dir = ({
    "domain/original/area/vesla/room172", "west",
  });
}

