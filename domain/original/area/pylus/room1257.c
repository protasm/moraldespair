inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Threshold to the Grand Rotunda";
    long_desc = "Threshold to the Grand Rotunda.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1256", "south",
        "domain/original/area/pylus/room1258", "north",
    });
}
