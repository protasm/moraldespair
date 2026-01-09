inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Hollow Sunk Narrow Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1561", "north",
        "domain/original/area/indel/room1559", "south",
    });
}
