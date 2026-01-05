inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In front of a temporary building";
    long_desc = "In front of a temporary building.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room389", "west",
        "domain/original/area/exedoria/room391", "east",
        "domain/original/area/exedoria/room904", "south",
    });
}
