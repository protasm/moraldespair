inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room43", "north",
        "chapter/prologue/area/sunken/room41", "south",
    });
}
