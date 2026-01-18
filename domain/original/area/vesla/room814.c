inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rusted Display";
    long_desc = "Rusted brackets and weapon grooves scar the walls, with a sagging rack in front. The floor is littered with flakes of iron and rot, and the air carries the taste of cold metal.";
    dest_dir = ({
        "domain/original/area/vesla/room796", "north",
    });
}

