inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bare Plot";
    long_desc = "A broad patch of bare earth interrupts the street, rimmed by broken foundations. Splintered posts and sunken stones hint at a lost structure beneath the weeds.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room192", "north",
    });
}

