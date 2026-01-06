inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Hollowed Tree";
    long_desc = "A Hollowed Tree.\n";
    dest_dir = ({
        "domain/original/area/preserve/room491", "west",
    });
}
