inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Western Road";
    long_desc = "The western road is split by deep cracks and littered with "
        + "shattered stone. The abandoned street bears the scars of "
        + "searing heat and talon-scores.\n";
    dest_dir = ({
        "domain/original/area/vesla/room131", "west",
        "domain/original/area/vesla/room129", "east",
        "domain/original/area/vesla/room420", "south",
    });
}

