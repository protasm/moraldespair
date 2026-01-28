inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Lamp Street";
  long_desc =
    "The street bends past a row of battered lamp posts and narrow doors. Faded\n"
    "plaster still carries traces of painted vines.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room413",
    "west" : "/chapter/prologue/area/refuge/room1147",
    "east" : "/chapter/prologue/area/refuge/room239",
    "north" : "/chapter/prologue/area/refuge/room415",
  ]);

  set_light(1);
}
