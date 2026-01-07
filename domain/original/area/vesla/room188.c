inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Forsaken Broken Lane";
    long_desc = "Broken plaques and toppled markers line the way, their inscriptions lost beneath soot. The street lies deserted, a ruin of learning.\n";
    dest_dir = ({
        "domain/original/area/vesla/room189", "west",
        "domain/original/area/vesla/room187", "east",
        "domain/original/area/vesla/room738", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "north");
}

int block_structure() {
    write("Rubble fills the exit, leaving no route forward.\n");
    return 1;
}
