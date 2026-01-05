inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wooded Hallway";
    long_desc = "Wooded Hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room913", "east",
        "domain/original/area/exedoria/room909", "west",
    });
}
