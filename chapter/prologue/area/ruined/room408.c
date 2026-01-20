inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Empty Ledger";
  long_desc = "A low stone chamber lies open to weather, its floor thick with dust and mildew, with drips tracing the walls where plaster once held. Rust-tormented bars sag above a cracked counter, and a warped slot in the wall still hints at where coins once passed.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room217", "east",
  });
}

