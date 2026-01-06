inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Polema street";
    long_desc = "Polema street.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1233", "west",
        "domain/original/area/pylus/room1237", "east",
        "domain/original/area/pylus/room1236", "north",
    });
}
