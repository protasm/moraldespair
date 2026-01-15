inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The lane ends at a wider crossing, its stones paling where\n"
              + "sunlight reaches in. A toppled capstone rests near the curb, half\n"
              + "sunk in silt.\n";
    dest_dir = ({
        "domain/original/area/vesla/room166", "west",
        "domain/original/area/vesla/room191", "east",
        "domain/original/area/vesla/room744", "south",
    });
}


