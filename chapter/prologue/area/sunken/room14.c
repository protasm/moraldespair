inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Strewn Walk";
    long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room13", "north",
        "chapter/prologue/area/sunken/room15", "south",
    });
}
