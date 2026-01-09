inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "bleached bend";
    long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks stripe the walls, and fine ash mixes with grit underfoot.\n";
    dest_dir = ({
        "domain/original/area/candera/room111", "south",
        "domain/original/area/candera/room114", "east",
        "domain/original/area/candera/room113", "west",
    });
}
