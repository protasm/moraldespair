inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gnome Laboratory";
    long_desc = "Gnome Laboratory.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room926", "down",
        "domain/original/area/exedoria/room930", "up",
    });
}
