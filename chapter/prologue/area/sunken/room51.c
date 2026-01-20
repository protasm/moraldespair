inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Cut";
    long_desc = "The ground levels out into a broad, empty spread of fractured flagstone. Small pits and cracks show where repeated blows split the surface.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room52", "east",
        "chapter/prologue/area/sunken/room50", "west",
    });
}
