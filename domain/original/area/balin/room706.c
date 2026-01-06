inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Turkish Bath";
    long_desc = "Turkish Bath.\n";
    dest_dir = ({
        "domain/original/area/balin/room704", "west",
        "domain/original/area/balin/room710", "south",
        "domain/original/area/balin/room707", "north",
    });
}
