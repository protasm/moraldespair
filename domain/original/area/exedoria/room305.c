inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Brapnor Road";
    long_desc = "Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room306", "west",
        "domain/original/area/exedoria/room304", "east",
        "domain/original/area/exedoria/room393", "north",
    });
}
