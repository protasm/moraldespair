inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Entryway";
    long_desc = "South Entryway.\n";
    dest_dir = ({
        "domain/original/area/island/room704", "north",
    });
}
