inherit "room/room";

void create() {
  ::create();

  short_desc = "Sooted Row";
  long_desc = "Soot stains the surviving walls, and the lane sits in a hush of rot and dust. Warped shutters and mildewed frames lean inward, the fire-scarred row left in collapse and silence.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room147",
    "west":"/chapter/prologue/area/ruined/room842",
    "east":"/chapter/prologue/area/ruined/room840",
    "north":"/chapter/prologue/area/ruined/room843",
  ]);

  set_light(1);
}
