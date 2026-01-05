inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Naive";
    long_desc = "Naive.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1332", "south",
        "domain/original/area/anshelm/room1329", "west",
        "domain/original/area/anshelm/room1331", "east",
        "domain/original/area/anshelm/room1333", "north",
    });
}
