inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burned Area";
    long_desc = "PHASE0: this area suffered a fire before the city was abandoned";
    dest_dir = ({
        "domain/original/area/vesla/room842", "south",
        "domain/original/area/vesla/room843", "east",
        "domain/original/area/vesla/room202", "north",
    });
}

