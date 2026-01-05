inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Necrom's Gate";
    long_desc = "Necrom's Gate.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room384", "northwest",
        "domain/original/area/exedoria/room387", "southeast",
    });
}
