inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/balin/room612", "south",
        "domain/original/area/balin/room675", "west",
        "domain/original/area/balin/room676", "east",
        "domain/original/area/balin/room614", "north",
    });
}
