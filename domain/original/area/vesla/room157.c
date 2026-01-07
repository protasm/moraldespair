inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Southern Main Road";
    long_desc = "The main road is split and collapsed, its stones scattered among ruined foundations. The silence of the dead city hangs over the broken way.\n";
    dest_dir = ({
        "domain/original/area/vesla/room156", "south",
        "domain/original/area/vesla/room823", "west",
        "domain/original/area/vesla/room830", "east",
        "domain/original/area/vesla/room158", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "west");
    add_action("block_structure", "east");
}

int block_structure() {
    write("A long-collapsed structure leaves only rubble there.\n");
    return 1;
}
