inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
    dest_dir = ({
        "domain/original/area/candera/room43", "north",
        "domain/original/area/candera/room41", "south",
    });
}
