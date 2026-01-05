inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Keen Street Bridge";
    long_desc = "East Keen Street Bridge.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room337", "west",
        "domain/original/area/exedoria/room339", "east",
        "domain/original/area/exedoria/room604", "north",
    });
}
