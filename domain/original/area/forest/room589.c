inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest glade";
    long_desc = "A forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room594", "west",
        "domain/original/area/forest/room597", "south",
        "domain/original/area/forest/room590", "southwest",
        "domain/original/area/forest/room588", "northeast",
        "domain/original/area/forest/room598", "east",
        "domain/original/area/forest/room595", "north",
    });
}
