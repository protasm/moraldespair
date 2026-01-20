inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire- blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room48", "north",
        "chapter/prologue/area/sunken/room46", "south",
    });
}
