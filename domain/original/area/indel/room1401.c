inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City of Indel, Wilderness Gate";
    long_desc = "City of Indel, Wilderness Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1402", "south",
        "domain/original/area/indel/room1636", "east",
        "domain/original/area/indel/room1635", "west",
        "domain/original/area/roadway/room55", "exit",
    });
}
