inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iola way";
    long_desc = "Iola way.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1229", "south",
        "domain/original/area/pylus/room1244", "west",
        "domain/original/area/pylus/room1243", "east",
        "domain/original/area/pylus/room1227", "north",
    });
}
