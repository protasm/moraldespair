inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Library's entrance";
    long_desc = "Library's entrance.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room357", "south",
        "domain/original/area/exedoria/room361", "west",
        "domain/original/area/exedoria/room355", "east",
        "domain/original/area/exedoria/room362", "north",
    });
}
