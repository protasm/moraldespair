inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection in the gravel path";
    long_desc = "Intersection in the gravel path.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room379", "west",
        "domain/original/area/exedoria/room382", "southeast",
        "domain/original/area/exedoria/room381", "north",
    });
}
