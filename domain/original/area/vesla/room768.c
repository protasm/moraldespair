inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "PHASE0: The Inner Ward";
    dest_dir = ({
        "domain/original/area/vesla/room766", "southwest",
        "domain/original/area/vesla/room767", "west",
        "domain/original/area/vesla/room769", "east",
        "domain/original/area/vesla/room765", "south",
    });
}

