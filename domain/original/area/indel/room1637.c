inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Choked End";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits.\n\nA collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1627", "north",
    });
}
