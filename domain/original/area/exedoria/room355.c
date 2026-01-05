inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Drawbridge";
    long_desc = "Drawbridge.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room310", "east",
        "domain/original/area/exedoria/room356", "west",
    });
}
