inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeastern Green";
    long_desc = "Northeastern Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1706", "west",
        "domain/original/area/village-green/room1708", "south",
        "domain/original/area/village-green/room1710", "north",
    });
}
