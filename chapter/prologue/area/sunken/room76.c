inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sand-Choked Lane";
    long_desc = "A wide run of cracked stone stretches north and south, its center scoured to dust. Soot stains cling to the stone, and the air tastes of old smoke. No footprints remain; only layered grit records the years.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room86", "north",
        "chapter/prologue/area/sunken/room78", "south",
        "chapter/prologue/area/sunken/room75", "east",
        "chapter/prologue/area/sunken/room77", "west",
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
