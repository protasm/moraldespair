inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gray foyer";
    long_desc = "Gray foyer.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room917", "south",
        "domain/original/area/exedoria/room915", "north",
    });
}
