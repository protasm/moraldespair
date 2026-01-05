inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Embassy Row";
    long_desc = "Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room316", "west",
        "domain/original/area/exedoria/room323", "east",
        "domain/original/area/exedoria/room333", "north",
    });
}
