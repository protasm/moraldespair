inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keen Street East";
    long_desc = "Keen Street East.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room340", "west",
        "domain/original/area/exedoria/room342", "north",
    });
}
