inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Residential hallway";
    long_desc = "Residential hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1395", "west",
        "domain/original/area/pylus/room1397", "east",
        "domain/original/area/pylus/room1398", "north",
    });
}
