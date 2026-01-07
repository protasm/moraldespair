inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southwest Green";
    long_desc = "Southwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1718", "west",
        "domain/original/area/village-green/room1711", "north",
    });
}
