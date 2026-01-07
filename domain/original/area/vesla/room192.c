inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Forsaken Broken Lane";
    long_desc = "Broken plaques and toppled markers line the way, their inscriptions lost beneath soot. The street lies deserted, a ruin of learning.\n";
    dest_dir = ({
        "domain/original/area/vesla/room166", "west",
        "domain/original/area/vesla/room191", "east",
        "domain/original/area/vesla/room744", "south",
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
