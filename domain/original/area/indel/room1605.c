inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You move the partition to the side and walk into the back of the tent.";
    long_desc = "You move the partition to the side and walk into the back of the tent..\n";
    dest_dir = ({
        "domain/original/area/indel/room1602", "west",
    });
}
