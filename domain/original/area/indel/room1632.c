inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Ashen Silted Choked End";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "Carved blocks are shattered and glazed in places, a mix of chisel scars and burn\n"
                "pits.\n"
                "\n"
                "A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats\n"
                "the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1631", "east",
    });
}
