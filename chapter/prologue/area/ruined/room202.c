inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Way";
  long_desc = "The paving narrows here, uneven and chipped, with damp dust clotted along the edges. Empty brackets jut from the masonry overhead, their purpose lost to the quiet.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room203",
    "east":"/chapter/prologue/area/ruined/room201",
    "south":"/chapter/prologue/area/ruined/room844",
  ]);

  set_light(1);
}
