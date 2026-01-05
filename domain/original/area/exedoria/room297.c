inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Corigan Court Intersection";
    long_desc = "Corigan Court Intersection.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room296", "west",
    });
}
