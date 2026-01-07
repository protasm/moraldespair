inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Breached Western End of Wall Street";
    long_desc = "The city wall is broken here, its stones strewn across the street. Wall Street is a rubble-strewn trench running along the shattered defenses.\n";
    dest_dir = ({
        "domain/original/area/vesla/room171", "east",
        "domain/original/area/vesla/room168", "west",
    });
}

void init() {
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the way is impassable.\n");
    return 1;
}
