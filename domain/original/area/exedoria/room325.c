inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bend in an alley";
    long_desc = "Bend in an alley.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room326", "west",
        "domain/original/area/exedoria/room324", "south",
    });
}
