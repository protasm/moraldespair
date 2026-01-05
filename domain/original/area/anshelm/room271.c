inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western end of Kasernegade";
    long_desc = "Western end of Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room270", "east",
        "domain/original/area/anshelm/room272", "north",
    });
}
