inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Slave Auction:";
    long_desc = "Slave Auction:.\n";
    dest_dir = ({
        "domain/original/area/candera/room100", "east",
    });
}
