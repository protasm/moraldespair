inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "A narrow strip of sky opens above the north road, framed by broken rooflines. Shattered brick and mortar gather in drifts.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room162", "south",
        "chapter/prologue/area/ruined/room811", "east",
        "chapter/prologue/area/ruined/room164", "north",
    });

  set_light(1);
}


