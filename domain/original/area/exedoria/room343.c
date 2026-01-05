inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Statued lawn";
    long_desc = "Statued lawn.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room344", "south",
        "domain/original/area/exedoria/room340", "north",
    });
}
