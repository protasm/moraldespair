inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "North Church Road";
    long_desc = "North Church Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1582", "east",
        "domain/original/area/indel/room1580", "west",
    });
}
