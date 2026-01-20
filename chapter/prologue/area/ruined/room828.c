inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Curtained Room";
  long_desc = "A ragged curtain droops from a rusted rod, its hem greened with mildew. The bedstead is bare and cracked, and dust has drifted into the corners like ash.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room825", "north",
  });
}
