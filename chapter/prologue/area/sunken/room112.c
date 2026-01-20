inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bleached Bend";
    long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room111", "south",
        "chapter/prologue/area/sunken/room114", "east",
        "chapter/prologue/area/sunken/room113", "west",
    });
}
