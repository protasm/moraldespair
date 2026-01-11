inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "A shallow rut marks the center line, worn deep before the silence. Small piles\n"
                + "of gravel gather against the curb.\n";
    dest_dir = ({
        "domain/original/area/vesla/room208", "west",
        "domain/original/area/vesla/room210", "east",
        "domain/original/area/vesla/room395", "north",
    });
}
