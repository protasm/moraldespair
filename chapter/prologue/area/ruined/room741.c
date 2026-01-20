inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Bunks";
    long_desc = "Rows of low frames line the walls, their slats warped and gray with dust. Mildew softens the plaster, and the floor is worn smooth by vanished footsteps.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room748", "up",
        "chapter/prologue/area/ruined/room190", "south",
        "chapter/prologue/area/ruined/room747", "east",
        "chapter/prologue/area/ruined/room745", "north",
    });
}

