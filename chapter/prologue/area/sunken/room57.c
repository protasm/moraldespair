inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Drifted Platform";
    long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room1", "north",
        "chapter/prologue/area/sunken/room58", "south",
        "chapter/prologue/area/sunken/room964", "east",
        "chapter/prologue/area/sunken/room963", "west",
    });
}
