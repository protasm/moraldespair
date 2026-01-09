inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Crossing";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Walls to either side are chewed by blasts and blade scars, their faces peeled away.\n\nThe way opens into a broad break where several lines of ruin meet. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1405", "north",
        "domain/original/area/indel/room1584", "south",
        "domain/original/area/indel/room1508", "east",
        "domain/original/area/indel/room1407", "west",
    });
}
