inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "The river road bends past a slumped doorway, its threshold choked with debris. Pale lichen maps the stone, and no tracks disturb the dust.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room846", "south",
        "chapter/prologue/area/ruined/room146", "west",
        "chapter/prologue/area/ruined/room148", "east",
        "chapter/prologue/area/ruined/room841", "north",
    });
}
