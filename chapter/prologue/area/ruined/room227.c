inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Overgrown Park";
    long_desc = "Thick grass swallows old benches, leaving warped planks and rusted bolts. A sagging iron fence lists inward, half-buried in leaf mold.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room228", "north",
        "chapter/prologue/area/ruined/room118", "south",
        "chapter/prologue/area/ruined/room226", "east",
        "chapter/prologue/area/ruined/room230", "west",
    });
}


