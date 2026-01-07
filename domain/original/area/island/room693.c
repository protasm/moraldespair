inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entryway";
    long_desc = "Entryway.\n";
    dest_dir = ({
        "domain/original/area/island/room677", "west",
        "domain/original/area/island/room694", "south",
        "domain/original/area/island/room696", "north",
    });
}
