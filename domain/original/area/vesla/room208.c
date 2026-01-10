inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Road";
    long_desc = "The road narrows between blank fronts, their doors\n"
                + "hanging askew.\n"
                + "Wind has swept the stones clean in thin streaks.\n";
    dest_dir = ({
        "domain/original/area/vesla/room207", "west",
        "domain/original/area/vesla/room209", "east",
        "domain/original/area/vesla/room396", "north",
    });
}

