inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "The paving here is split by roots, forming a jagged seam. A toppled arch stone blocks part of the way.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room408", "west",
        "chapter/prologue/area/ruined/room216", "south",
        "chapter/prologue/area/ruined/room218", "north",
    });
}
