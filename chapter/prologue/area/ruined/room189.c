inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The paving here is uneven, with gaps where stones have been pulled free or sunk. A narrow passage to the south is choked with grit and a slow spread of grass.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room190", "west",
        "chapter/prologue/area/ruined/room188", "east",
        "chapter/prologue/area/ruined/room739", "south",
    });
}


