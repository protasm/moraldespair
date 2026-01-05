inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Alley entrance";
    long_desc = "Alley entrance.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room328", "south",
        "domain/original/area/exedoria/room303", "north",
    });
}
