inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Brapnor Road";
    long_desc = "End of Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room306", "east",
        "domain/original/area/exedoria/room331", "northwest",
        "domain/original/area/exedoria/room308", "south",
    });
}
