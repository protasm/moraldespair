inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eroded Rise";
    long_desc = "A jagged seam in the paving marks the line of a sunken run. Ash and grit collect in corners, damped by occasional trickles.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room91", "north",
        "chapter/prologue/area/sunken/room89", "south",
        "chapter/prologue/area/sunken/room1094", "east",
        "chapter/prologue/area/sunken/room1093", "west",
    });
}
