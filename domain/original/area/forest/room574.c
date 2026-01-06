inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Forest Glade";
    long_desc = "Forest Glade.\n";
    dest_dir = ({
        "domain/original/area/forest/room568", "northeast",
        "domain/original/area/forest/room565", "north",
    });
}
