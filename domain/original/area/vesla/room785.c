inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Pens";
    long_desc = "Pen walls stand in crooked rows, their boards gray and powdery. Cobwebs hang from the corners, and the floor is gritty with old straw dust.";
    dest_dir = ({
        "domain/original/area/vesla/room775", "south",
    });
}

