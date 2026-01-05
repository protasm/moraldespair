inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gateway to Upper Bailey";
    long_desc = "Gateway to Upper Bailey.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room264", "south",
        "domain/original/area/anshelm/room282", "west",
        "domain/original/area/anshelm/room1198", "east",
        "domain/original/area/anshelm/room266", "north",
    });
}
