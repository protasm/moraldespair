inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hallway";
    long_desc = "Hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1373", "up",
        "domain/original/area/pylus/room1370", "west",
        "domain/original/area/pylus/room1371", "east",
        "domain/original/area/pylus/room1368", "south",
    });
}
