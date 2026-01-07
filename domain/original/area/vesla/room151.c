inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked Riverside Street and Broken Main Road";
    long_desc = "Two ruined streets meet in a heap of collapsed stone and shattered timbers. The crossing is quiet, the stones glazed by ancient heat.\n";
    dest_dir = ({
        "domain/original/area/vesla/room816", "south",
        "domain/original/area/vesla/room150", "west",
        "domain/original/area/vesla/room205", "east",
        "domain/original/area/vesla/room152", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
}

int block_exit() {
    write("There is only debris; the structure collapsed years ago.\n");
    return 1;
}
