inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "The lane runs east and west between silent foundations, their\n"
              + "doorways collapsed into piles of brick and slate. A brittle vine\n"
              + "clings to the mortar seams.\n";
    dest_dir = ({
        "domain/original/area/vesla/room178", "east",
        "domain/original/area/vesla/room186", "west",
    });
}

