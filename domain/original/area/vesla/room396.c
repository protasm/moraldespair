inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Antique Shop";
    long_desc = "PHASE0: antique shop";
    dest_dir = ({
        "domain/original/area/vesla/room208", "south",
    });
}

