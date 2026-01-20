inherit "room/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "The paving is patched with mismatched stones, as if repairs once stalled here. A low mound of rubble spills from the west, half blocking the way before the crossing.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room176",
      "north":"/chapter/prologue/area/ruined/room178",
    ]);

  set_light(1);
}
