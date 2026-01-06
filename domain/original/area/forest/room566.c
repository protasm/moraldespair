inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dark forest glade";
    long_desc = "A dark forest glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room567", "southwest",
        "domain/original/area/forest/room565", "northeast",
    });
}
