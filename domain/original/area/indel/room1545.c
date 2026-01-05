inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ambassador Gate";
    long_desc = "Ambassador Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1546", "east",
        "domain/original/area/indel/room1434", "west",
    });
}
