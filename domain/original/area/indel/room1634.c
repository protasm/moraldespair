inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Farm Road";
    long_desc = "Farm Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1633", "west",
    });
}
