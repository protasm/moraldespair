inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Abandoned Park";
    long_desc = "A once-open lawn is now a tangle of thorn and nettle. Broken edging stones ring the growth like a half-lost border.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room119", "south",
        "chapter/prologue/area/ruined/room815", "west",
        "chapter/prologue/area/ruined/room227", "east",
        "chapter/prologue/area/ruined/room231", "north",
    });
}
