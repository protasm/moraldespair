inherit "/room/room";

void create() {
  ::create();

  short_desc = "Stone Avenue";
  long_desc =
    "The avenue is paved in broad stones worn smooth by time. A row of bent iron\n"
    "lamps leans over the gutter.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1189",
    "west" : "/chapter/prologue/area/refuge/room1187",
  ]);

  set_light(1);
}
