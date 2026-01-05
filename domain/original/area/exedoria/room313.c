inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beginning of Embassy Row";
    long_desc = "Beginning of Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room314", "east",
        "domain/original/area/exedoria/room312", "north",
    });
}
