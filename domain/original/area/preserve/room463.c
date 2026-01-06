inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sink Hole";
    long_desc = "Sink Hole.\n";
    dest_dir = ({
        "domain/original/area/preserve/room461", "east",
    });
}
