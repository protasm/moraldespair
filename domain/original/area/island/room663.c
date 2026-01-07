inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room670", "south",
        "domain/original/area/balin/room662", "west",
        "domain/original/area/balin/room664", "east",
        "domain/original/area/balin/room671", "north",
    });
}
