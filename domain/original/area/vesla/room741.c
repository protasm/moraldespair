inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Bunks";
    long_desc = "Rows of low frames line the walls, their slats warped and gray with\n"
                + "dust. Mildew softens the plaster, and the floor is worn smooth by\n"
                + "vanished footsteps.\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "up",
        "domain/original/area/vesla/room190", "south",
        "domain/original/area/vesla/room747", "east",
        "domain/original/area/vesla/room745", "north",
    });
}

