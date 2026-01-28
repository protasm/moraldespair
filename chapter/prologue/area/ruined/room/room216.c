inherit "//chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "A shallow channel cuts along the path, filled with grit and broken tile. The air is cool and still between the close walls.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room215",
      "west":"/chapter/prologue/area/ruined/room/room402",
      "east":"/chapter/prologue/area/ruined/room/room403",
      "north":"/chapter/prologue/area/ruined/room/room217",
    ]);

}
