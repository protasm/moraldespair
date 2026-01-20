inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The lane ends at a wider crossing, its stones paling where sunlight reaches in. A toppled capstone rests near the curb, half sunk in silt.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room166", "west",
        "chapter/prologue/area/ruined/room191", "east",
        "chapter/prologue/area/ruined/room744", "south",
    });
}


