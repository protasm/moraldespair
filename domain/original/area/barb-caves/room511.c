inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Underground Pond";
    long_desc = "Underground Pond.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room512", "southwest",
        "domain/original/area/barb-caves/room518", "west",
        "domain/original/area/barb-caves/room510", "south",
    });
}
