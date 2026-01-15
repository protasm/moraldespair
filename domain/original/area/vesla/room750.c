inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Quarters";
    long_desc = "A cramped chamber shows the shadow of old sleeping rows in the dust.\n"
                + "Plaster has fallen in sheets, and the boards are dark with mildew.\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "west",
    });
}

