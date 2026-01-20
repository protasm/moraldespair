inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "The way runs quiet between squat walls, its stones dulled and uneven. Old carvings are worn to nubs, nearly erased by weather.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room214",
      "north":"/chapter/prologue/area/ruined/room216",
    ]);

  set_light(1);
}
