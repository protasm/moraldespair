inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Westroad";
    long_desc = "Westroad is split by deep cracks and littered with shattered stone. The abandoned street bears the scars of searing heat and talon-scores.\n";
    dest_dir = ({
        "domain/original/area/vesla/room133", "west",
        "domain/original/area/vesla/room131", "east",
        "domain/original/area/vesla/room421", "south",
    });
}

void init() {
    add_action("block_structure", "south");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
