inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple entry";
    long_desc = "Temple entry.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1376", "south",
        "domain/original/area/pylus/room1254", "north",
    });
}
