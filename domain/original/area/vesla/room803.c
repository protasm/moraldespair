inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Reeking Ruin Alley";
    long_desc = "Stagnant filth and ash cling to the broken stones, and a sour reek hangs in the air. The alleyway is collapsed and deserted.\n";
    dest_dir = ({
        "domain/original/area/vesla/room802", "east",
        "domain/original/area/vesla/room804", "south",
    });
}

void init() {
    ::init();
    add_action("block_structure", "south");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
