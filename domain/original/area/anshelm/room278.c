inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kasernegade";
    long_desc = "Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room279", "east",
        "domain/original/area/anshelm/room277", "west",
    });
}
