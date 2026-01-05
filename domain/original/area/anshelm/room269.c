inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kasernegade";
    long_desc = "Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room268", "east",
        "domain/original/area/anshelm/room270", "west",
    });
}
