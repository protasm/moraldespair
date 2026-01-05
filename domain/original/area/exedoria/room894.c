inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormitory foyer";
    long_desc = "Dormitory foyer.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room528", "west",
        "domain/original/area/exedoria/room895", "south",
        "domain/original/area/exedoria/room903", "north",
    });
}
