inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rusted Display";
    long_desc = "Rusted brackets and weapon grooves scar the walls, with a sagging rack in\n"
                + "front. The floor is littered with flakes of iron and rot, and the air\n"
                + "carries the taste of cold metal.\n";
    dest_dir = ({
        "domain/original/area/vesla/room796", "north",
    });
}

