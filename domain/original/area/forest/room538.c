inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gryphon Nest";
    long_desc = "Gryphon Nest.\n";
    dest_dir = ({
        "domain/original/area/forest/room537", "northeast",
    });
}
