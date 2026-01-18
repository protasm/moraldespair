inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The way crosses another street in a small square of worn stone. Old foundations crowd the corners, their rooms open and empty. Wind moves freely through the gaps.";
    dest_dir = ({
        "domain/original/area/vesla/room740", "south",
        "domain/original/area/vesla/room191", "west",
        "domain/original/area/vesla/room189", "east",
        "domain/original/area/vesla/room741", "north",
    });
}


