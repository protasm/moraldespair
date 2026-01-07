inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northwest Green";
    long_desc = "Northwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1700", "south",
        "domain/original/area/village-green/room1689", "west",
        "domain/original/area/village-green/room1691", "east",
        "domain/original/area/village-green/room1694", "north",
    });
}
