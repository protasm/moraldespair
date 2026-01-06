inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Residential hallway";
    long_desc = "Residential hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1396", "east",
        "domain/original/area/pylus/room1362", "south",
    });
}
