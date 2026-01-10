inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sacra Way";
    long_desc = "The street opens slightly, revealing pale stone flecked\n"
                + "with lichen.\n"
                + "A shallow depression holds rain-dark stains.\n";
    dest_dir = ({
        "domain/original/area/vesla/room409", "west",
        "domain/original/area/vesla/room218", "south",
        "domain/original/area/vesla/room220", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
}

int block_exit() {
    write("Crumbling ruins bar that direction completely.\n");
    return 1;
}
