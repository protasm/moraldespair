inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Freemason's";
    long_desc = "Freemason's.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1210", "south",
        "domain/original/area/pylus/room1208", "east",
        "domain/original/area/pylus/room1211", "north",
    });
}
