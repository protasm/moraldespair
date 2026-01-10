inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Street";
    long_desc = "Rutted Street.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room291", "west",
        "domain/original/area/exedoria/room293", "east",
        "domain/original/area/exedoria/room383", "south",
    });
}
