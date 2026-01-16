inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Empty Ledger";
  long_desc = "A low stone chamber lies open to weather, its floor thick with dust\n"
              "and mildew, with drips tracing the walls where plaster once held.\n"
              "Rust-tormented bars sag above a cracked counter, and a warped slot in\n"
              "the wall still hints at where coins once passed.\n";
  dest_dir = ({
    "domain/original/area/vesla/room217", "east",
  });
}

