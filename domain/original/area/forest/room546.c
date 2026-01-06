inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest glade";
    long_desc = "A forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room543", "west",
        "domain/original/area/forest/room556", "south",
        "domain/original/area/forest/room547", "southwest",
        "domain/original/area/forest/room545", "northeast",
        "domain/original/area/forest/room557", "east",
        "domain/original/area/forest/room544", "north",
    });
}
