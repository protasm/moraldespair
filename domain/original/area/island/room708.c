inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Turkish Bath";
    long_desc = "Turkish Bath.\n";
    dest_dir = ({
        "domain/original/area/balin/room702", "west",
        "domain/original/area/balin/room707", "south",
        "domain/original/area/balin/room709", "north",
    });
}
