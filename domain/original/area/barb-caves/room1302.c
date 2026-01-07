inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Top of the mine shaft";
    long_desc = "Top of the mine shaft.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1303", "down",
        "domain/original/area/barb-caves/room1301", "west",
    });
}
