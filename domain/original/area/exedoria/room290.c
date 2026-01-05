inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Monument Circle, Main Street";
    long_desc = "Monument Circle, Main Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room299", "south",
        "domain/original/area/exedoria/room289", "west",
        "domain/original/area/exedoria/room291", "east",
        "domain/original/area/exedoria/room369", "north",
    });
}
