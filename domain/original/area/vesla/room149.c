inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Weeds crowd the seams of the paving, softening the road into a green ribbon. The air is damp and still along the empty course.";
    dest_dir = ({
        "domain/original/area/vesla/room150", "east",
        "domain/original/area/vesla/room148", "west",
    });
}
