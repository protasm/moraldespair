inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Central slave bazaar";
    long_desc = "Central slave bazaar.\n";
    dest_dir = ({
        "domain/original/area/island/room728", "west",
        "domain/original/area/island/room731", "east",
        "domain/original/area/island/room733", "south",
    });
}
