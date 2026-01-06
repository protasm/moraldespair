inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pylus road";
    long_desc = "Pylus road.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1207", "south",
        "domain/original/area/pylus/room1205", "north",
    });
}
