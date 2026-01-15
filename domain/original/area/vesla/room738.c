inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Blind Alley";
    long_desc = "The alley narrows to a blind wall, its cobbles slick with grime and\n"
                + "decay. Rotten beams lean overhead, and a stale dampness pools where the\n"
                + "light dies.\n";
    dest_dir = ({
        "domain/original/area/vesla/room188", "south",
    });
}

