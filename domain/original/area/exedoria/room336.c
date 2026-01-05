inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keen Street";
    long_desc = "Keen Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room335", "west",
        "domain/original/area/exedoria/room337", "east",
        "domain/original/area/exedoria/room602", "north",
    });
}
