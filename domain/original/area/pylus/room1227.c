inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iola way";
    long_desc = "Iola way.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1228", "south",
        "domain/original/area/pylus/room1247", "west",
        "domain/original/area/pylus/room1246", "east",
        "domain/original/area/pylus/room1224", "north",
    });
}
