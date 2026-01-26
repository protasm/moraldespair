inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Park Crossroads";
  long_desc = "The crossing is choked with gravel and dead leaves where a broad street meets a narrower lane. Fallen posts and a tilted sign hold a silence settled over long neglect.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room233",
    "west":"/chapter/prologue/area/ruined/room/room117",
    "east":"/chapter/prologue/area/ruined/room/room115",
    "north":"/chapter/prologue/area/ruined/room/room172",
  ]);

}
