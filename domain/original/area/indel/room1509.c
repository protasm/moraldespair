inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Merchant's Row, south of Saul's Formal Wear";
    long_desc = "East Merchant's Row, south of Saul's Formal Wear.\n";
    dest_dir = ({
        "domain/original/area/indel/room1624", "north",
        "domain/original/area/indel/room1510", "east",
        "domain/original/area/indel/room1508", "west",
    });
}
