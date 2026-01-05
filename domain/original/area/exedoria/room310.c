inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Middle of Lilu Lane";
    long_desc = "Middle of Lilu Lane.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room355", "west",
        "domain/original/area/exedoria/room311", "south",
        "domain/original/area/exedoria/room309", "north",
    });
}
