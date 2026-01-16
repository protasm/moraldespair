inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dingy alleyway";
    long_desc = "PHASE0: A Dingy Alleyway";
    dest_dir = ({
        "domain/original/area/vesla/room813", "south",
        "domain/original/area/vesla/room792", "west",
        "domain/original/area/vesla/room796", "east",
        "domain/original/area/vesla/room797", "north",
    });
}

