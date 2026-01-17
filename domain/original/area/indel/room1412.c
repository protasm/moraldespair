inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Leaning\n"
                "walls show long cuts and scorch trails, as if steel and heat worried them for\n"
                "hours. The way runs on in a narrow line, hemmed by broken walls left to weather.\n"
                "Moss and pale mold cling to the damp pockets, and nothing moves except drifting\n"
                "grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1411", "east",
        "domain/original/area/indel/room1413", "west",
    });
}
