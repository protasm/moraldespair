inherit "room/room";

void create() {
  ::create();

  short_desc = "Park Crossroads";
  long_desc = "The crossing is choked with gravel and dead leaves where a broad street meets a narrower lane. Fallen posts and a tilted sign hold a silence settled over long neglect.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room233", "south",
    "chapter/prologue/area/ruined/room117", "west",
    "chapter/prologue/area/ruined/room115", "east",
    "chapter/prologue/area/ruined/room172", "north",
  });

  set_light(1);
}
