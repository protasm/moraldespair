inherit "room/room";

void create() {
  ::create();

  short_desc = "Worn Way";
  long_desc = "The paving breaks into small islands, the gaps filled with dark soil and rot. The street narrows toward a wider crossing ahead, where the stones dip slightly.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room197",
    "west":"/chapter/prologue/area/ruined/room195",
  ]);

  set_light(1);
}

