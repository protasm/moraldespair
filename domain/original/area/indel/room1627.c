inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible for";
    long_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible for.\n";
    dest_dir = ({
        "domain/original/area/indel/room1637", "south",
        "domain/original/area/indel/room1404", "west",
    });
}
