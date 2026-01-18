inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash-Streaked Crossing";
    long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
    dest_dir = ({
        "domain/original/area/candera/room44", "north",
        "domain/original/area/candera/room42", "south",
        "domain/original/area/candera/room1033", "west",
    });
}
