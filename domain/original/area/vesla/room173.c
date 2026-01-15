inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road narrows between low heaps of stone, the old curbs almost\n"
              + "buried under grit and grass. A tilted signboard rests against a\n"
              + "wall, its paint long gone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room172", "south",
        "domain/original/area/vesla/room232", "west",
        "domain/original/area/vesla/room736", "east",
        "domain/original/area/vesla/room174", "north",
    });
}

