inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Gritted Choked End";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1518", "west",
    });
}
