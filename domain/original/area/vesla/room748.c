inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bare Bunks";
    long_desc = "The room is divided by low rails where thin beds once rested in rows.\n"
                + "Mildew and rot soften the timbers, and the air lies flat and stale.\n";
    dest_dir = ({
        "domain/original/area/vesla/room751", "west",
        "domain/original/area/vesla/room741", "down",
        "domain/original/area/vesla/room752", "south",
        "domain/original/area/vesla/room750", "east",
        "domain/original/area/vesla/room749", "north",
    });
}

