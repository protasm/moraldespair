inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Bridge";
  long_desc = "The bridge arches over a dry channel, its sides worn smooth. Moss gathers\nalong the parapet where hands once rested.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room340",
    "west":"/chapter/prologue/area/silent/room338",
  ]);

  set_light(1);
}
