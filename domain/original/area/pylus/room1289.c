inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gate of Triumph";
    long_desc = "Gate of Triumph.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1290", "south",
        "domain/original/area/pylus/room1222", "west",
        "domain/original/area/pylus/room1224", "east",
        "domain/original/area/pylus/room1291", "north",
    });
}
