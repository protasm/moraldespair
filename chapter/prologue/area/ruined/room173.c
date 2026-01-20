inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road narrows between low heaps of stone, the old curbs almost buried under grit and grass. A tilted signboard rests against a wall, its paint long gone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room172", "south",
        "chapter/prologue/area/ruined/room232", "west",
        "chapter/prologue/area/ruined/room736", "east",
        "chapter/prologue/area/ruined/room174", "north",
    });
}

