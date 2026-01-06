inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pylus road";
    long_desc = "Pylus road.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1216", "southwest",
        "domain/original/area/pylus/room1222", "east",
        "domain/original/area/pylus/room1217", "southeast",
        "domain/original/area/pylus/room1214", "north",
    });
}
