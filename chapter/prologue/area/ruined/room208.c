inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "The road narrows between blank fronts, their doors hanging askew. Wind has swept the stones clean in thin streaks.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room207",
      "east":"/chapter/prologue/area/ruined/room209",
      "north":"/chapter/prologue/area/ruined/room396",
    ]);

  set_light(1);
}
