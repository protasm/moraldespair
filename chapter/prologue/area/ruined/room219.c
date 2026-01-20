inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "The street opens slightly, revealing pale stone flecked with lichen. A shallow depression holds rain-dark stains.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room409",
      "south":"/chapter/prologue/area/ruined/room218",
      "north":"/chapter/prologue/area/ruined/room220",
    ]);

  set_light(1);
}
