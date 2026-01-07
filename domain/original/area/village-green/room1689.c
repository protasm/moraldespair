inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northwest Green";
    long_desc = "Northwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1699", "south",
        "domain/original/area/village-green/room1690", "east",
        "domain/original/area/village-green/room1688", "north",
    });
}
