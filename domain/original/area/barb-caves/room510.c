inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Barbarian Clearing";
    long_desc = "Barbarian Clearing.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room511", "north",
    });
}
