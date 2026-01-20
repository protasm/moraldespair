inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room1017", "north",
        "chapter/prologue/area/sunken/room1016", "south",
        "chapter/prologue/area/sunken/room72", "east",
        "chapter/prologue/area/sunken/room74", "west",
    });
}
