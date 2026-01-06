inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/balin/room611", "south",
        "domain/original/area/balin/room674", "east",
        "domain/original/area/balin/room613", "north",
    });
}
