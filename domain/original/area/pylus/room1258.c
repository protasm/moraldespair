inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Grand Rotunda";
    long_desc = "Grand Rotunda.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1259", "west",
        "domain/original/area/pylus/room1362", "east",
        "domain/original/area/pylus/room1257", "south",
    });
}
