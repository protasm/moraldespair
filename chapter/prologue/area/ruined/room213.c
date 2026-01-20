inherit "room/room";

void create() {
  ::create();

    short_desc = "Southern End";
    long_desc = "The way thins into broken stones, the once- straight line sagging. Fallen trim and damp rubble gather at the end of the road.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room212",
      "east":"/chapter/prologue/area/ruined/room399",
      "north":"/chapter/prologue/area/ruined/room214",
    ]);

  set_light(1);
}
