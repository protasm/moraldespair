inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Lilu Lane";
    long_desc = "End of Lilu Lane.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room354", "west",
        "domain/original/area/exedoria/room313", "south",
        "domain/original/area/exedoria/room311", "north",
    });
}
