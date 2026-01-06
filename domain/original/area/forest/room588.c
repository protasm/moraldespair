inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dark forest glade";
    long_desc = "A dark forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room595", "west",
        "domain/original/area/forest/room598", "south",
        "domain/original/area/forest/room589", "southwest",
        "domain/original/area/forest/room586", "northeast",
        "domain/original/area/forest/room589", "east",
        "domain/original/area/forest/room587", "north",
    });
}
