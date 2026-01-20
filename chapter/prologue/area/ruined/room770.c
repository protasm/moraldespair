inherit "room/room";

void create() {
  ::create();

    short_desc = "Broken Stalls";
    long_desc = "Splintered stall walls lean inward, their rails slick with mildew. A cracked feeding trough sits dry, and dust lies thick where hooves once churned.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room790",
      "west":"/chapter/prologue/area/ruined/room765",
      "east":"/chapter/prologue/area/ruined/room773",
      "north":"/chapter/prologue/area/ruined/room791",
    ]);

  set_light(1);
}

