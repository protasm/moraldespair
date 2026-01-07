inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Westroad";
    long_desc = "Westroad is split by deep cracks and littered with shattered stone. The abandoned street bears the scars of dragonfire.\n";
    dest_dir = ({
        "domain/original/area/vesla/room130", "west",
        "domain/original/area/vesla/room128", "east",
        "domain/original/area/vesla/room419", "south",
    });
}
