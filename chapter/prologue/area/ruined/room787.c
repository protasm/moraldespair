inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Saddling Corner";
    long_desc = "A narrow corner holds a low block and scarred posts, now slick with mold. The surrounding boards are split, and the air is stale with wet wood.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room774", "north",
    });
}

