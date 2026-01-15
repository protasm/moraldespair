inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Inner Walk";
    long_desc = "A narrow run of cobbles skirts the wall, sunk and slick with damp.\n"
                + "The high masonry is stained with mildew, and fallen stones crowd the\n"
                + "edge of the path.\n";
    dest_dir = ({
        "domain/original/area/vesla/room181", "east",
        "domain/original/area/vesla/room183", "west",
    });
}

