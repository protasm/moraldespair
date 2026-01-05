inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kasernegade";
    long_desc = "Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room267", "west",
        "domain/original/area/anshelm/room277", "east",
        "domain/original/area/anshelm/room1200", "north",
    });
}
