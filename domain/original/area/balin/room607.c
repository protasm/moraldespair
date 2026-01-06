inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A narrow path between the dunes";
    long_desc = "A narrow path between the dunes.\n";
    dest_dir = ({
        "domain/original/area/balin/room606", "south",
        "domain/original/area/balin/room628", "east",
        "domain/original/area/balin/room608", "north",
    });
}
