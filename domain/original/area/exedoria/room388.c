inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern path through the University";
    long_desc = "Eastern path through the University.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room389", "east",
        "domain/original/area/exedoria/room387", "west",
    });
}
