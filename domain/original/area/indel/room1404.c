inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Mossy Bleached Crossing";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1403", "north",
        "domain/original/area/indel/room1405", "south",
        "domain/original/area/indel/room1627", "east",
        "domain/original/area/indel/room1626", "west",
    });
}
