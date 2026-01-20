inherit "room/room";

void create() {
  ::create();

  short_desc = "Worn Way";
  long_desc = "The street straightens here, hemmed by sagging fronts and shutterless frames. A line of rust runs along the gutter, and thin weeds take the joints slowly.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room195", "east",
    "chapter/prologue/area/ruined/room193", "west",
  });

  set_light(1);
}

