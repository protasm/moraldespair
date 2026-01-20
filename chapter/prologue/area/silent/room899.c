inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "A formal walkway continues between shuttered halls. Only wind and birds move\namong the stones.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room902", "south",
    "chapter/prologue/area/silent/room900", "east",
    "chapter/prologue/area/silent/room898", "north",
  });

  set_light(1);
}
