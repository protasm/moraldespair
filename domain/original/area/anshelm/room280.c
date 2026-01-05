inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern end of Kasernegade";
    long_desc = "Eastern end of Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room279", "west",
        "domain/original/area/anshelm/room1201", "south",
    });
}
