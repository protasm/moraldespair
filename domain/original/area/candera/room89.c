inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Cut";
    long_desc = "The ground levels out into a broad, empty spread of fractured flagstone. Small pits and cracks show where repeated blows split the surface.";
    dest_dir = ({
        "domain/original/area/candera/room90", "north",
        "domain/original/area/candera/room88", "south",
    });
}
