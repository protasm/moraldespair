inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Formal gardens";
    long_desc = "Formal gardens.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1362", "west",
        "domain/original/area/pylus/room1393", "east",
        "domain/original/area/pylus/room1394", "south",
    });
}
