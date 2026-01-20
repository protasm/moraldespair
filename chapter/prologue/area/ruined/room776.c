inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cracked Trough";
    long_desc = "A stone trough is split down the middle, its basin crusted with lime. Rot has eaten the surrounding planks, leaving gaps filled with dust and mold.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room782", "south",
        "chapter/prologue/area/ruined/room775", "west",
        "chapter/prologue/area/ruined/room777", "east",
        "chapter/prologue/area/ruined/room781", "north",
    });
}

