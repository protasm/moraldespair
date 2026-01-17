inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "Leaning walls show long cuts and scorch trails, as if steel and heat worried\n"
                "them for hours. The way runs on in a narrow line, hemmed by broken walls left to\n"
                "weather. Moss and pale mold cling to the damp pockets, and nothing moves except\n"
                "drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1414", "east",
        "domain/original/area/indel/room1416", "west",
    });
}
