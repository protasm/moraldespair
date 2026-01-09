inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1542", "east",
        "domain/original/area/indel/room1540", "west",
    });
}
