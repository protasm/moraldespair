inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest glade";
    long_desc = "A forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room585", "southwest",
        "domain/original/area/forest/room586", "west",
        "domain/original/area/forest/room583", "east",
        "domain/original/area/forest/room582", "south",
    });
}
