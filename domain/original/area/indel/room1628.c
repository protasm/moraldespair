inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Broken Bend";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The remains of pillars stand jagged, split and fused by old force. The passage angles hard here, squeezed between leaning stone. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1403", "east",
        "domain/original/area/indel/room1629", "down",
    });
}
