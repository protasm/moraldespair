inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pillow Shop:";
    long_desc = "Pillow Shop:.\n";
    dest_dir = ({
        "domain/original/area/candera/room100", "west",
    });
}
