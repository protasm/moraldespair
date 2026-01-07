inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked River Street and Broken South Main";
    long_desc = "Two ruined streets meet in a heap of collapsed stone and shattered timbers. The crossing is quiet, the scars of dragonfire still visible.\n";
    dest_dir = ({
        "domain/original/area/vesla/room816", "south",
        "domain/original/area/vesla/room150", "west",
        "domain/original/area/vesla/room205", "east",
        "domain/original/area/vesla/room152", "north",
    });
}

void init() {
    add_action("block_structure", "south");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
