inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dark Southwest Green";
    long_desc = "Dark Southwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1721", "east",
        "domain/original/area/village-green/room1719", "north",
    });
}
