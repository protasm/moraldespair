inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Silver Street";
    long_desc = "End of Silver Street.\n";
    dest_dir = ({
        "domain/original/area/balin/room620", "east",
        "domain/original/area/balin/room618", "south",
    });
}
