inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A private corner in the garden";
    long_desc = "A private corner in the garden.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1392", "north",
    });
}
