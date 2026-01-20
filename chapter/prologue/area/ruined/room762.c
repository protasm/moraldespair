inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Bunk Row";
  long_desc = "A long narrow room holds the remains of low platforms, their frames rotted and collapsed. The air is stale with old mildew, and a strip of wall hooks suggests ordered kit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room761", "northeast",
  });
}
