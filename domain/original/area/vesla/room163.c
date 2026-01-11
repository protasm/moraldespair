inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Main Road";
    long_desc = "A narrow strip of sky opens above the north road, framed by broken rooflines.\n"
                + "Shattered brick and mortar gather in drifts.\n";
    dest_dir = ({
        "domain/original/area/vesla/room162", "south",
        "domain/original/area/vesla/room811", "east",
        "domain/original/area/vesla/room164", "north",
    });
}

