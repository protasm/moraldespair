inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Air";
    long_desc = "Temple of Air.\n";
    dest_dir = ({
        "domain/original/area/candera/room84", "down",
    });
}
