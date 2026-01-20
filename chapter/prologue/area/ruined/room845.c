inherit "room/room";

void create() {
  ::create();

  short_desc = "Scorched Pass";
  long_desc = "Scorched boards lie half-buried in damp dust, the passage silent and ruined. A low sill and slumped counter are soft with rot and mildew, hinting at a trade stall left to waste.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room846",
    "north":"/chapter/prologue/area/ruined/room146",
  ]);

  set_light(1);
}
