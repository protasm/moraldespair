inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western End of Wall Street";
    long_desc = "Western End of Wall Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room171", "east",
        "domain/original/area/vesla/room168", "west",
    });
}
