inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Court";
  long_desc = "The court widens toward a collapsed corner, its paving buckled and wet with seepage. A half-ruined post and iron ring suggest where orders and notices once hung.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room766",
    "northwest":"/chapter/prologue/area/ruined/room767",
    "south":"/chapter/prologue/area/ruined/room758",
    "southwest":"/chapter/prologue/area/ruined/room757",
    "northeast":"/chapter/prologue/area/ruined/room769",
    "east":"/chapter/prologue/area/ruined/room770",
    "north":"/chapter/prologue/area/ruined/room768",
  ]);

  set_light(1);
}
