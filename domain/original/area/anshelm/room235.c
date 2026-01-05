inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before the Anshelm Gatehouse";
    long_desc = "Before the Anshelm Gatehouse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room236", "north",
    });
}
