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
        "domain/original/area/vesla/room168", "east",
    });
}
