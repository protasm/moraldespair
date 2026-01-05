inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Main Street";
    long_desc = "Main Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room368", "south",
        "domain/original/area/exedoria/room287", "west",
        "domain/original/area/exedoria/room289", "east",
        "domain/original/area/exedoria/room367", "north",
    });
}
