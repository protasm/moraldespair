inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rotted Racks";
    long_desc = "Warped wooden frames cling to the walls, their joints loose and\n"
                + "splintered. Cobwebs gather in the corners, and a sour dampness hangs over\n"
                + "the floor.\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "south",
    });
}

