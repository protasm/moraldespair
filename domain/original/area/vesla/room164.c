inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Northern Main Road";
    long_desc = "The northern main road is cracked and heaved, with chunks of masonry strewn across it. Heat-blistered stone and deep gouges linger like the passage of something vast. Grease-dark stains and splintered bones collect in sheltered corners.\n";
    dest_dir = ({
        "domain/original/area/vesla/room163", "south",
        "domain/original/area/vesla/room812", "east",
        "domain/original/area/vesla/room165", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "east");
}

int block_structure() {
    write("Nothing but rubble lies beyond; the building fell ages ago.\n");
    return 1;
}
