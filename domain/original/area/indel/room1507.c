inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cobblestone courtyard";
    long_desc = "Cobblestone courtyard.\n";
    dest_dir = ({
        "domain/original/area/indel/room1448", "south",
    });
}
