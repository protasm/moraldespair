inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Strewn Walk";
    long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room81", "north",
        "chapter/prologue/area/sunken/room83", "south",
        "chapter/prologue/area/sunken/room1098", "east",
        "chapter/prologue/area/sunken/room1097", "west",
    });
}
