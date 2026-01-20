inherit "room/room";

void create() {
  ::create();

    short_desc = "River-Main Junction";
    long_desc = "Two dead roads cross in a scatter of broken cobbles. A fractured drain grate sits at the center, packed with mud and leaves.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room816",
      "west":"/chapter/prologue/area/ruined/room150",
      "east":"/chapter/prologue/area/ruined/room205",
      "north":"/chapter/prologue/area/ruined/room152",
    ]);

  set_light(1);
}

