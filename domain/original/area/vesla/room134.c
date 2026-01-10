inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Gate of Vesla";
    long_desc = "Western Gate of Vesla";
    dest_dir = ({
        "domain/original/area/vesla/room133", "east",
        "domain/original/area/roadway/room29", "exit",
    });
}

void init() {
    ::init();
    add_action("block_exit", "exit");
}

int block_exit() {
    write("The ruined gate is choked with stone; the wilderness beyond is impassable.\n");
    return 1;
}
