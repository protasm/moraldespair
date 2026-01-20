inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire- blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room82", "north",
        "chapter/prologue/area/sunken/room85", "east",
        "chapter/prologue/area/sunken/room84", "west",
    });
}
