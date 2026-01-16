inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "PHASE0: The Inner Ward";
    dest_dir = ({
        "domain/original/area/vesla/room768", "east",
        "domain/original/area/vesla/room765", "southeast",
        "domain/original/area/vesla/room766", "south",
    });
}

