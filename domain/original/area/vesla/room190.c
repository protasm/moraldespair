inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way\n";
    dest_dir = ({
        "domain/original/area/vesla/room740", "south",
        "domain/original/area/vesla/room191", "west",
        "domain/original/area/vesla/room189", "east",
        "domain/original/area/vesla/room741", "north",
    });
}

