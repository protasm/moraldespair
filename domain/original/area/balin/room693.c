inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entryway";
    long_desc = "Entryway.\n";
    dest_dir = ({
        "domain/original/area/balin/room677", "west",
        "domain/original/area/balin/room694", "south",
        "domain/original/area/balin/room696", "north",
    });
}
