inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1509", "east",
        "domain/original/area/indel/room1406", "west",
    });
}
