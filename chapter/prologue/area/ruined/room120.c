inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Walk";
  long_desc = "A hollowed stretch of passage runs between damp stone walls. The roof timbers have fallen away, leaving the corridor open to dull light and slow rain.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room121", "west",
    "chapter/prologue/area/ruined/room119", "east",
    "chapter/prologue/area/ruined/room223", "south",
  });

  set_light(1);
}
