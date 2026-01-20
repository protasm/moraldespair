inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The lane runs east and west between silent foundations, their doorways collapsed into piles of brick and slate. A brittle vine clings to the mortar seams.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room178", "east",
        "chapter/prologue/area/ruined/room186", "west",
    });
}

