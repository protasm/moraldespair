inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Main Street";
    long_desc = "Main Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room288", "west",
        "domain/original/area/exedoria/room290", "east",
        "domain/original/area/exedoria/room366", "south",
    });
}
