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
        "domain/original/area/vesla/room228", "north",
        "domain/original/area/vesla/room118", "south",
        "domain/original/area/vesla/room226", "east",
        "domain/original/area/vesla/room230", "west",
    });
}
