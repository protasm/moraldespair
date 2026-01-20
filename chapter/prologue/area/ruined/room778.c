inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hay Loft";
    long_desc = "A collapsed loft hangs above, its beams broken and draped in cobwebs. Dry chaff dust coats the ground, now darkened by years of damp.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room783", "southwest",
        "chapter/prologue/area/ruined/room777", "west",
        "chapter/prologue/area/ruined/room780", "northwest",
        "chapter/prologue/area/ruined/room779", "south",
    });
}

