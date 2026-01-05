inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Army Encampment Gate";
    long_desc = "Army Encampment Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1593", "south",
        "domain/original/area/indel/room1595", "west",
    });
}
