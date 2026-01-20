inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash-Streaked Crossing";
    long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room27", "east",
        "chapter/prologue/area/sunken/room29", "west",
    });
}
