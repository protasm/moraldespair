inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Collapsed Sunk Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1546", "east",
        "domain/original/area/indel/room1434", "west",
    });
}
