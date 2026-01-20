inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Drifted Platform";
    long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room98", "north",
        "chapter/prologue/area/sunken/room100", "south",
    });
}
