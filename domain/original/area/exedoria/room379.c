inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gravel path on the hill";
    long_desc = "Gravel path on the hill.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room380", "east",
        "domain/original/area/exedoria/room378", "west",
    });
}
