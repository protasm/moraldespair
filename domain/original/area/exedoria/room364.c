inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A bend in the hallway";
    long_desc = "A bend in the hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room365", "west",
        "domain/original/area/exedoria/room362", "south",
    });
}
