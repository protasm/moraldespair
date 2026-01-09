inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "shattered cut";
    long_desc = "The ground levels out into a broad, empty spread of fractured flagstone. Small pits and cracks show where repeated blows split the surface.\n";
    dest_dir = ({
        "domain/original/area/candera/room8", "east",
        "domain/original/area/candera/room6", "west",
    });
}
