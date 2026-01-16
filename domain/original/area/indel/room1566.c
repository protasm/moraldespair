inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Dusted Sunk Narrow Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1567", "north",
        "domain/original/area/indel/room1565", "south",
    });
}
