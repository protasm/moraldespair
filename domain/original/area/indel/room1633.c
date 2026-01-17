inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Blasted Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Carved\n"
                "blocks are shattered and glazed in places, a mix of chisel scars and burn pits.\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Thin\n"
                "lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1634", "east",
        "domain/original/area/indel/room1402", "west",
    });
}
