inherit "room/room";

void create() {
  ::create();

    short_desc = "Hay Loft";
    long_desc = "A collapsed loft hangs above, its beams broken and draped in cobwebs. Dry chaff dust coats the ground, now darkened by years of damp.";
    dest_dir = ([
      "southwest":"/chapter/prologue/area/ruined/room783",
      "west":"/chapter/prologue/area/ruined/room777",
      "northwest":"/chapter/prologue/area/ruined/room780",
      "south":"/chapter/prologue/area/ruined/room779",
    ]);

  set_light(1);
}

