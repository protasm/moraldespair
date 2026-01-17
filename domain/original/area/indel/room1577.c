inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "Leaning walls show long cuts and scorch trails, as if steel and heat worried\n"
                "them for hours.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Thin\n"
                "lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1578", "east",
        "domain/original/area/indel/room1576", "west",
    });
}
