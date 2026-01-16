inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "PHASE0: The Inner Ward";
    dest_dir = ({
        "domain/original/area/vesla/room757", "west",
        "domain/original/area/vesla/room759", "south",
        "domain/original/area/vesla/room766", "northwest",
        "domain/original/area/vesla/room765", "north",
    });
}

