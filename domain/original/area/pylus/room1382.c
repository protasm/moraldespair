inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of Peace";
    long_desc = "Hall of Peace.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1383", "west",
        "domain/original/area/pylus/room1381", "east",
        "domain/original/area/pylus/room1387", "south",
    });
}
