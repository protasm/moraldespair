inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire-\nblackened patches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room14", "north",
        "domain/original/area/candera/room16", "south",
        "domain/original/area/candera/room973", "east",
    });
}
