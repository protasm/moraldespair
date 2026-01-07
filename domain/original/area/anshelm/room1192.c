inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Chamber";
    long_desc = "Collapsed Chamber.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room240", "west",
    });
}
