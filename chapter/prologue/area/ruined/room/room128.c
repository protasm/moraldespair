inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Westroad Threshold";
  long_desc = "The road angles west through a narrowed gap between leaning stonework. Chipped blocks and pale grit mark a boundary that time has left without purpose.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room129",
    "east":"/chapter/prologue/area/ruined/room/room127",
  ]);

}
