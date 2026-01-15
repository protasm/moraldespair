inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Low Pens";
    long_desc = "Low pen walls barely stand, their joints loose and sagging. Mildew\n"
                + "freckles the timbers, and a damp chill clings to the floor.\n";
    dest_dir = ({
        "domain/original/area/vesla/room779", "southeast",
        "domain/original/area/vesla/room783", "south",
        "domain/original/area/vesla/room776", "west",
        "domain/original/area/vesla/room778", "east",
        "domain/original/area/vesla/room780", "north",
    });
}

