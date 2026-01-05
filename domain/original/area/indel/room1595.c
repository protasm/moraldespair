inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Punishment Grounds";
    long_desc = "Punishment Grounds.\n";
    dest_dir = ({
        "domain/original/area/indel/room1594", "east",
        "domain/original/area/indel/room1596", "west",
    });
}
