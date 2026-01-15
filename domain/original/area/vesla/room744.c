inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bare Plot";
    long_desc = "A broad patch of bare earth interrupts the street, rimmed by broken\n"
                + "foundations. Splintered posts and sunken stones hint at a lost structure\n"
                + "beneath the weeds.\n";
    dest_dir = ({
        "domain/original/area/vesla/room192", "north",
    });
}

