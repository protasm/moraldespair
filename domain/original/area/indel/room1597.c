inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cavalry Gate";
    long_desc = "Cavalry Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1598", "north",
        "domain/original/area/indel/room1596", "south",
        "domain/original/area/indel/room1533", "west",
    });
}
