inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Salon";
  long_desc =
    "A quiet room holds a few toppled chairs and a cracked mosaic floor. The walls\n"
    "are stained with old smoke and damp.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room1332",
    "west" : "/chapter/prologue/area/refuge/room1329",
    "east" : "/chapter/prologue/area/refuge/room1331",
    "north" : "/chapter/prologue/area/refuge/room1333",
  ]);

  set_light(1);
}
