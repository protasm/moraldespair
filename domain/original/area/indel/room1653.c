inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Lichen Silted Choked End";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1583", "up",
    });
}
