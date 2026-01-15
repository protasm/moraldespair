inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallen Way";
    long_desc = "The way crosses another street in a small square of worn stone.\n"
              + "Old foundations crowd the corners, their rooms open and empty.\n"
              + "Wind moves freely through the gaps.\n";
    dest_dir = ({
        "domain/original/area/vesla/room740", "south",
        "domain/original/area/vesla/room191", "west",
        "domain/original/area/vesla/room189", "east",
        "domain/original/area/vesla/room741", "north",
    });
}

