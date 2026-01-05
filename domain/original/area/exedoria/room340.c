inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keen Street";
    long_desc = "Keen Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room339", "west",
        "domain/original/area/exedoria/room341", "east",
        "domain/original/area/exedoria/room343", "south",
    });
}
