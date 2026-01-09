inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cracked Drop";
    long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red\nstreaks mark where metal once lay, now long gone.\n";
    dest_dir = ({
        "domain/original/area/candera/room57", "east",
        "domain/original/area/candera/room1027", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
