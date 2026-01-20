inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined City";
  long_desc = "The ruins of a large city.";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room30",
    "south":"/chapter/prologue/area/roadway/room43",
    "west":"/chapter/prologue/area/roadway/room13",
    "east":"/chapter/prologue/area/roadway/room16",
    "city":"/chapter/prologue/area/ruined/room115",
  ]);

  add_exit_alias("c", "city");

  set_light(1);
}
