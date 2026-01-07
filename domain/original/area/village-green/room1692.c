inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeast Green";
    long_desc = "Northeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1702", "south",
        "domain/original/area/village-green/room1691", "west",
        "domain/original/area/village-green/room1706", "east",
        "domain/original/area/village-green/room1703", "north",
    });
}
