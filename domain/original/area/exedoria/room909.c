inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Grand Foyer";
    long_desc = "Grand Foyer.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room914", "up",
        "domain/original/area/exedoria/room911", "west",
        "domain/original/area/exedoria/room912", "east",
        "domain/original/area/exedoria/room908", "south",
    });
}
