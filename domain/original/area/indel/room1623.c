inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Silted Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. The\n"
                "remains of pillars stand jagged, split and fused by old force. The way runs on\n"
                "in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the\n"
                "shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1643", "north",
        "domain/original/area/indel/room1510", "south",
    });
}
void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("The way is blocked by a choke of fallen stone.\n");
    return 1;
}
