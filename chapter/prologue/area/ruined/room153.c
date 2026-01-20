inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "A broad stretch of paving runs north and south, worn smooth in places. The bases of old walls sit empty, their timbers long gone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room820", "west",
        "chapter/prologue/area/ruined/room152", "south",
        "chapter/prologue/area/ruined/room154", "north",
    });
}

