inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Polema street";
    long_desc = "Polema street.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1234", "south",
        "domain/original/area/pylus/room1231", "west",
        "domain/original/area/pylus/room1235", "east",
        "domain/original/area/pylus/room1238", "north",
    });
}
