inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Basalt River Corner";
    long_desc = "Cracked basalt paving meets the river road, its stones\n"
                + "slick with old stains.\n"
                + "A collapsed wall spills rubble into the corner, and\n"
                + "weeds root in the gaps.\n";
    dest_dir = ({
        "domain/original/area/vesla/room144", "east",
        "domain/original/area/vesla/room142", "north",
    });
}
