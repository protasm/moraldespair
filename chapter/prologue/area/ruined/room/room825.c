inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Landing";
  long_desc = "The upper landing is choked with dust, its rail warped and soft with rot. Closed doors lean inward, and a cracked mirror keeps a dim memory of bright rooms now gone to mildew.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room828",
    "west":"/chapter/prologue/area/ruined/room/room826",
    "up":"/chapter/prologue/area/ruined/room/room829",
    "down":"/chapter/prologue/area/ruined/room/room824",
    "north":"/chapter/prologue/area/ruined/room/room827",
  ]);

}
