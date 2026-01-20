inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "A shallow rut marks the center line, worn deep before the silence. Small piles of gravel gather against the curb.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room208", "west",
        "chapter/prologue/area/ruined/room210", "east",
        "chapter/prologue/area/ruined/room395", "north",
    });
}
