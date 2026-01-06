inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest glade";
    long_desc = "A forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room546", "southwest",
        "domain/original/area/forest/room544", "west",
        "domain/original/area/forest/room558", "east",
        "domain/original/area/forest/room557", "south",
    });
}
