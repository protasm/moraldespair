inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple Shop";
    long_desc = "Temple Shop.\n";
    dest_dir = ({
        "domain/original/area/balin/room672", "west",
        "domain/original/area/balin/room663", "south",
    });
}
