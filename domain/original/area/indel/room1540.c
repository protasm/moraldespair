inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Mossy Narrow Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1541", "east",
        "domain/original/area/indel/room1539", "west",
    });
}
