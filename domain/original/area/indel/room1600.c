inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Post Exchange";
    long_desc = "Post Exchange.\n";
    dest_dir = ({
        "domain/original/area/indel/room1603", "north",
        "domain/original/area/indel/room1602", "south",
        "domain/original/area/indel/room1601", "east",
        "domain/original/area/indel/room1598", "west",
    });
}
