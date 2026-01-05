inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "North Gate";
    long_desc = "North Gate.\n";
    dest_dir = ({
        "domain/original/area/candera/room57", "south",
        "domain/original/area/candera/room2", "east",
        "domain/original/area/candera/room56", "west",
    });
}
