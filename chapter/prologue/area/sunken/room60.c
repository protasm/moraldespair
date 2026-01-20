inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Approach";
    long_desc = "A straight corridor of paving is split by collapsed slabs and sinkholes. Small pits and cracks show where repeated blows split the surface.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room59", "north",
        "chapter/prologue/area/sunken/room61", "south",
        "chapter/prologue/area/sunken/room969", "east",
        "chapter/prologue/area/sunken/room968", "west",
    });
}
