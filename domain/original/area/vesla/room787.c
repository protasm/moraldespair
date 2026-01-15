inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Saddling Corner";
    long_desc = "A narrow corner holds a low block and scarred posts, now slick with\n"
                + "mold. The surrounding boards are split, and the air is stale with wet\n"
                + "wood.\n";
    dest_dir = ({
        "domain/original/area/vesla/room774", "north",
    });
}

