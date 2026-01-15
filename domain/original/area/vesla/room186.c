inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallen Way";
    long_desc = "Broken lintels and scattered tiles mark the edges of the way.\n"
              + "Shadows pool in the empty frames of doorways, and loose plaster\n"
              + "has long turned to dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room185", "east",
        "domain/original/area/vesla/room187", "west",
    });
}
