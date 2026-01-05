inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Gatehouse";
    long_desc = "Castle Gatehouse.\n";
    dest_dir = ({
        "domain/original/area/indel/room1585", "north",
    });
}
