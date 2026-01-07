inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gate House";
    long_desc = "Gate House.\n";
    dest_dir = ({
        "domain/original/area/balin/room676", "south",
        "domain/original/area/balin/room614", "west",
        "domain/original/area/balin/room693", "east",
        "domain/original/area/balin/room686", "north",
    });
}
