inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened\npatches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room1017", "north",
        "domain/original/area/candera/room1016", "south",
        "domain/original/area/candera/room72", "east",
        "domain/original/area/candera/room74", "west",
    });
}
