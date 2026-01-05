inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Barracks Gate";
    long_desc = "City Barracks Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1539", "east",
        "domain/original/area/indel/room1537", "west",
    });
}
