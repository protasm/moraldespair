inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cave Passage";
    long_desc = "Cave Passage.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1292", "southwest",
        "domain/original/area/barb-caves/room511", "east",
    });
}
