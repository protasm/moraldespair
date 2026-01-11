inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Street of the Bells";
    long_desc = "Street of the Bells\n";
    dest_dir = ({
        "domain/original/area/vesla/room843", "south",
        "domain/original/area/vesla/room202", "west",
        "domain/original/area/vesla/room200", "east",
    });
}
