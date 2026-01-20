inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rotted Racks";
    long_desc = "Warped wooden frames cling to the walls, their joints loose and splintered. Cobwebs gather in the corners, and a sour dampness hangs over the floor.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room748", "south",
    });
}

