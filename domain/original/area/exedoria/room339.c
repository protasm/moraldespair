inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keen Street Bridge";
    long_desc = "Keen Street Bridge.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room340", "east",
        "domain/original/area/exedoria/room338", "west",
    });
}
