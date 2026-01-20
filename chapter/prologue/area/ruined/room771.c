inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cold Hearth";
    long_desc = "A broad stone hearth squats in the center, dark with soot and long without heat. An anvil stump and iron tools sit rusted among cinders and damp ash.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room772", "east",
        "chapter/prologue/area/ruined/room769", "west",
    });
}

