inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southern end of alley";
    long_desc = "Southern end of alley.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room323", "south",
        "domain/original/area/exedoria/room325", "north",
    });
}
