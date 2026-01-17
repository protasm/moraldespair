inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Choked End";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "The remains of pillars stand jagged, split and fused by old force.\n"
                "\n"
                "A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats\n"
                "the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1511", "south",
    });
}
