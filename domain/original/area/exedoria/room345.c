inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Manicured lawn";
    long_desc = "Manicured lawn.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room346", "south",
        "domain/original/area/exedoria/room344", "north",
    });
}
