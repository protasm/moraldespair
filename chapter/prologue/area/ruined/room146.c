inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Flat stones lie loose underfoot, some tipped into a shallow rut. A broken lintel rests against a wall, half buried in grit.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room845", "south",
        "chapter/prologue/area/ruined/room145", "west",
        "chapter/prologue/area/ruined/room147", "east",
        "chapter/prologue/area/ruined/room842", "north",
    });
}
