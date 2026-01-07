inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Study";
    long_desc = "Study.\n";
    dest_dir = ({
        "domain/original/area/island/room657", "west",
    });
}
