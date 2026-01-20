inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "Broken lintels and scattered tiles mark the edges of the way. Shadows pool in the empty frames of doorways, and loose plaster has long turned to dust.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room185", "east",
        "chapter/prologue/area/ruined/room187", "west",
    });
}

