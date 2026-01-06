inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest glade";
    long_desc = "A forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room569", "southwest",
        "domain/original/area/forest/room571", "northeast",
        "domain/original/area/forest/room563", "west",
        "domain/original/area/forest/room562", "north",
    });
}
