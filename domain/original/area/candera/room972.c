inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Trader's Shack";
    long_desc = "Trader's Shack.\n";
    dest_dir = ({
        "domain/original/area/candera/room94", "south",
        "domain/original/area/candera/room62", "west",
    });
}
