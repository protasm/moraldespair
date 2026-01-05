inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cavernous foyer";
    long_desc = "Cavernous foyer.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room348", "west",
        "domain/original/area/exedoria/room347", "east",
        "domain/original/area/exedoria/room345", "north",
    });
}
