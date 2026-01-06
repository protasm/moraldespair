inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple rotunda";
    long_desc = "Temple rotunda.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1377", "south",
        "domain/original/area/pylus/room1381", "west",
        "domain/original/area/pylus/room1384", "east",
        "domain/original/area/pylus/room1375", "north",
    });
}
