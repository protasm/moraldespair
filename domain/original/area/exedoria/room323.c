inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Embassy Row";
    long_desc = "End of Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room317", "west",
        "domain/original/area/exedoria/room324", "north",
    });
}
