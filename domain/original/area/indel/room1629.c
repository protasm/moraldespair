inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Art of Darkness";
    long_desc = "The Art of Darkness.\n";
    dest_dir = ({
        "domain/original/area/indel/room1628", "up",
    });
}
