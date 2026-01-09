inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bleached Bend";
    long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks\nstripe the walls, and fine ash mixes with grit underfoot.\n";
    dest_dir = ({
        "domain/original/area/candera/room49", "south",
        "domain/original/area/candera/room51", "east",
    });
}
