inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Dark Hole in the Ground";
    long_desc = "A Dark Hole in the Ground.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room316", "north",
    });
}
