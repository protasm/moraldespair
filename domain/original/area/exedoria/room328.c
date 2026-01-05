inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dark alley";
    long_desc = "Dark alley.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room327", "south",
        "domain/original/area/exedoria/room329", "north",
    });
}
