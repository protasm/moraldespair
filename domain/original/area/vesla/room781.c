inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guttered Bays";
    long_desc = "A row of bays opens along the wall, their gates missing and frames\n"
                + "twisted. Water stains creep up the stone base, and the air is heavy with\n"
                + "mildew.\n";
    dest_dir = ({
        "domain/original/area/vesla/room776", "south",
    });
}

