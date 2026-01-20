inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Market Lot";
  long_desc = "Low foundations ring a vacant patch, silent beneath dust, mildew, and rot. A broken sign frame hints at trade, the lot left to crumble.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room173", "west",
  });
}
