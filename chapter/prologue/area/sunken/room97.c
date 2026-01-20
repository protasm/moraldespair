inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pitted Turn";
    long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has piled sand against one side, leaving the other scoured bare.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room428", "north",
        "chapter/prologue/area/sunken/room98", "east",
        "chapter/prologue/area/sunken/room96", "west",
    });
}
