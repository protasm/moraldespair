inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "ash-streaked crossing";
    long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.\n";
    dest_dir = ({
        "domain/original/area/candera/room100", "west",
    });
}
