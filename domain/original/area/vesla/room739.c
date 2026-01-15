inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Practice Hall";
    long_desc = "Scuffed boards and long tables fill a wide room, now gray with dust.\n"
                + "Faded tally marks and peg holes linger on the walls, hinting at lessons\n"
                + "once kept here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room189", "north",
    });
}

