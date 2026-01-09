inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "faded corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room91", "east",
        "domain/original/area/candera/room1132", "up",
    });
}
