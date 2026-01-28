inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Road Start";
  long_desc = "A broader road begins near a low wall of fallen stone. The surface is cracked\nbut still passable.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room385",
    "southeast":"/chapter/prologue/area/silent/room386",
    "north":"/chapter/prologue/area/silent/room383",
  ]);

  set_light(1);
}
