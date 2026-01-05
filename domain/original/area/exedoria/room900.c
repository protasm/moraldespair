inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "School of Business";
    long_desc = "School of Business.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room899", "west",
        "domain/original/area/exedoria/room901", "north",
    });
}
