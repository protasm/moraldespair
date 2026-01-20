inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "The southern road narrows between leaning walls. Loose slate and tile litter the paving.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room156", "south",
        "chapter/prologue/area/ruined/room823", "west",
        "chapter/prologue/area/ruined/room830", "east",
        "chapter/prologue/area/ruined/room158", "north",
    });
}

