inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A bend in the alley";
    long_desc = "A bend in the alley.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room325", "east",
        "domain/original/area/exedoria/room327", "north",
    });
}
