inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Second Bank of Anshelm";
    long_desc = "Second Bank of Anshelm.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room240", "west",
    });
}
