inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Dusted Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1530", "north",
        "domain/original/area/indel/room1532", "south",
    });
}
