inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Brapnor Road";
    long_desc = "Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room305", "west",
        "domain/original/area/exedoria/room303", "east",
        "domain/original/area/exedoria/room330", "north",
    });
}
