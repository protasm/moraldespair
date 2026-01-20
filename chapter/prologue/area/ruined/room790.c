inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sunk Stalls";
    long_desc = "Stall floors have sunk into the earth, leaving the boards slanted and warped. Mildew climbs the posts, and a musty silence settles in the gaps.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room770", "north",
    });
}

