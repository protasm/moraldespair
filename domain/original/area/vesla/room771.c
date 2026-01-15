inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cold Hearth";
    long_desc = "A broad stone hearth squats in the center, dark with soot and long\n"
                + "without heat. An anvil stump and iron tools sit rusted among cinders and\n"
                + "damp ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room772", "east",
        "domain/original/area/vesla/room769", "west",
    });
}

