inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guttered Bays";
    long_desc = "A row of bays opens along the wall, their gates missing and frames twisted. Water stains creep up the stone base, and the air is heavy with mildew.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room776", "south",
    });
}

