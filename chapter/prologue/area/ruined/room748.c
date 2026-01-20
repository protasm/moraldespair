inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bare Bunks";
    long_desc = "The room is divided by low rails where thin beds once rested in rows. Mildew and rot soften the timbers, and the air lies flat and stale.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room751", "west",
        "chapter/prologue/area/ruined/room741", "down",
        "chapter/prologue/area/ruined/room752", "south",
        "chapter/prologue/area/ruined/room750", "east",
        "chapter/prologue/area/ruined/room749", "north",
    });
}

