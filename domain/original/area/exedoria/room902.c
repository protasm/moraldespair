inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Construction site";
    long_desc = "Construction site.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room899", "north",
    });
}
