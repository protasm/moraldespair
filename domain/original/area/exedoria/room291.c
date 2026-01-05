inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Main Street";
    long_desc = "Main Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room298", "south",
        "domain/original/area/exedoria/room290", "west",
        "domain/original/area/exedoria/room292", "east",
        "domain/original/area/exedoria/room370", "north",
    });
}
