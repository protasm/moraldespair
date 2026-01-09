inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burned-Out Space";
    long_desc = "Rubble forms uneven mounds where structures once stood. The "
        + "scorched surfaces and clawed stone speak of a violent, fiery "
        + "ruin.\n";
    dest_dir = ({
        "domain/original/area/vesla/room787", "south",
        "domain/original/area/vesla/room773", "west",
        "domain/original/area/vesla/room775", "east",
        "domain/original/area/vesla/room786", "north",
    });
}
