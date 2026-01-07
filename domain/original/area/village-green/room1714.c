inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southeast Green";
    long_desc = "Southeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1711", "west",
        "domain/original/area/village-green/room1715", "east",
        "domain/original/area/village-green/room1702", "north",
    });
}
