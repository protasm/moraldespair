inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Courtyard";
    long_desc = "Courtyard.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1365", "south",
        "domain/original/area/pylus/room1368", "north",
    });
}
