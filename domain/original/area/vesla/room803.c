inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Reeking Ruin Alley";
    long_desc = "Stagnant filth and ash cling to the broken stones, and a sour "
        + "reek hangs in the air. The alleyway is collapsed and deserted.\n";
    dest_dir = ({
        "domain/original/area/vesla/room802", "east",
        "domain/original/area/vesla/room804", "south",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
}

int block_exit() {
    write("Just ruins and broken stone remain; the structure gave out long ago.\n");
    return 1;
}
