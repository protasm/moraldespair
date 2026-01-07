inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Walk by a Dead Park";
    long_desc = "Blackened branches arch over a walkway of cracked flagstones, their shade long burned away. The path is quiet, littered with ash and broken masonry.\n";
    dest_dir = ({
        "domain/original/area/vesla/room224", "south",
        "domain/original/area/vesla/room122", "west",
        "domain/original/area/vesla/room120", "east",
        "domain/original/area/vesla/room425", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("Rubble blocks the way; the structure has long since fallen.\n");
    return 1;
}
