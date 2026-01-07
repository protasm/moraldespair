inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entryway";
    long_desc = "Entryway.\n";
    dest_dir = ({
        "domain/original/area/island/room700", "west",
        "domain/original/area/island/room702", "south",
    });
}
