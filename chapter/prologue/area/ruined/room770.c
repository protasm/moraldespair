inherit "room/room";

void create() {
  ::create();

    short_desc = "Broken Stalls";
    long_desc = "Splintered stall walls lean inward, their rails slick with mildew. A cracked feeding trough sits dry, and dust lies thick where hooves once churned.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room790", "south",
        "chapter/prologue/area/ruined/room765", "west",
        "chapter/prologue/area/ruined/room773", "east",
        "chapter/prologue/area/ruined/room791", "north",
    });

  set_light(1);
}

