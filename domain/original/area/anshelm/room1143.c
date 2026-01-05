inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Anshelm Lounge";
    long_desc = "Anshelm Lounge.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room236", "east",
        "domain/original/area/anshelm/room1204", "west",
    });
}
