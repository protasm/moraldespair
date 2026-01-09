inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Breached Western End of the Wall Road";
    long_desc = "The city wall is broken here, its stones strewn across the "
        + "street. The wall-side street is a rubble-strewn trench running"
        + " along the shattered defenses.\n";
    dest_dir = ({
        "domain/original/area/vesla/room171", "east",
        "domain/original/area/vesla/room168", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "east");
}

int block_exit() {
    write("Nothing but fallen masonry lies there; it's impassable.\n");
    return 1;
}
