inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern District";
    long_desc = "Eastern District.\n";
    dest_dir = ({
        "domain/original/area/balin/room725", "west",
        "domain/original/area/balin/room730", "south",
    });
}
