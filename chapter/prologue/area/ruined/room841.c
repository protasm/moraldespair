inherit "room/room";

void create() {
  ::create();

  short_desc = "Sooted Row";
  long_desc = "Soot stains the surviving walls, and the lane sits in a hush of rot and dust. Warped shutters and mildewed frames lean inward, the fire-scarred row left in collapse and silence.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room147", "south",
    "chapter/prologue/area/ruined/room842", "west",
    "chapter/prologue/area/ruined/room840", "east",
    "chapter/prologue/area/ruined/room843", "north",
  });

  set_light(1);
}
