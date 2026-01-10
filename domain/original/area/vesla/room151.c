inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "River Street and South Main";
    long_desc = "River Street and South Main";
    dest_dir = ({
        "domain/original/area/vesla/room816", "south",
        "domain/original/area/vesla/room150", "west",
        "domain/original/area/vesla/room205", "east",
        "domain/original/area/vesla/room152", "north",
    });
}

