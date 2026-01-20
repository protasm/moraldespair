inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Quarters";
    long_desc = "A cramped chamber shows the shadow of old sleeping rows in the dust. Plaster has fallen in sheets, and the boards are dark with mildew.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room748", "west",
    });
}

