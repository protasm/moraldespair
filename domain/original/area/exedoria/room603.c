inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Flagstoned entry";
    long_desc = "Flagstoned entry.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room915", "south",
        "domain/original/area/exedoria/room337", "north",
    });
}
