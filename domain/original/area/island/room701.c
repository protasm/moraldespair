inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entryway";
    long_desc = "Entryway.\n";
    dest_dir = ({
        "domain/original/area/balin/room700", "west",
        "domain/original/area/balin/room702", "south",
    });
}
