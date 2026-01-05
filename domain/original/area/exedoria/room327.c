inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dark and narrow alley";
    long_desc = "Dark and narrow alley.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room326", "south",
        "domain/original/area/exedoria/room328", "north",
    });
}
