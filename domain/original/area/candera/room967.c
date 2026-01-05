inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Candera Information Bureau";
    long_desc = "Candera Information Bureau.\n";
    dest_dir = ({
        "domain/original/area/candera/room1125", "north",
        "domain/original/area/candera/room59", "east",
    });
}
