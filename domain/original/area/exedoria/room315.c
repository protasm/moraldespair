inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Embassy Row";
    long_desc = "Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room320", "south",
        "domain/original/area/exedoria/room314", "west",
        "domain/original/area/exedoria/room316", "east",
        "domain/original/area/exedoria/room321", "north",
    });
}
