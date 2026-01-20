inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire- blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room63", "north",
        "chapter/prologue/area/sunken/room65", "south",
        "chapter/prologue/area/sunken/room427", "east",
        "chapter/prologue/area/sunken/room429", "west",
    });
}
