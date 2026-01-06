inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hallway";
    long_desc = "Hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1366", "west",
        "domain/original/area/pylus/room1364", "east",
        "domain/original/area/pylus/room1367", "north",
    });
}
