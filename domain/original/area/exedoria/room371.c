inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Park path intersection";
    long_desc = "Park path intersection.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room370", "south",
        "domain/original/area/exedoria/room372", "west",
        "domain/original/area/exedoria/room378", "east",
        "domain/original/area/exedoria/room373", "north",
    });
}
