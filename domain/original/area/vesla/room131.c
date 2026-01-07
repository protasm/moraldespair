inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Westroad";
    long_desc = "Westroad is split by deep cracks and littered with shattered stone. The abandoned street bears the scars of searing heat and talon-scores.\n";
    dest_dir = ({
        "domain/original/area/vesla/room132", "west",
        "domain/original/area/vesla/room130", "east",
        "domain/original/area/vesla/room858", "north",
    });
}
