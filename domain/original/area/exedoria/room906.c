inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Science lecture hall";
    long_desc = "Science lecture hall.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room904", "west",
    });
}
