inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Hollow Walk";
  long_desc = "A hollowed stretch of passage runs between damp stone walls. The roof timbers have fallen away, leaving the corridor open to dull light and slow rain.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room121",
    "east":"/chapter/prologue/area/ruined/room/room119",
    "south":"/chapter/prologue/area/ruined/room/room223",
  ]);

}
