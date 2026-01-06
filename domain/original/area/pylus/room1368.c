inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Courtyard";
    long_desc = "Courtyard.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1367", "south",
        "domain/original/area/pylus/room1369", "north",
    });
}
