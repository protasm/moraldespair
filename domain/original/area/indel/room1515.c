inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Eroded Faded Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1516", "east",
        "domain/original/area/indel/room1514", "west",
    });
}
