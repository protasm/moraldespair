inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallen Way";
    long_desc = "The way widens a little, its stones cracked in a shallow fan where\n"
              + "a side street meets from the north. The remains of a low wall\n"
              + "trail off into weeds.\n";
    dest_dir = ({
        "domain/original/area/vesla/room188", "west",
        "domain/original/area/vesla/room186", "east",
        "domain/original/area/vesla/room737", "north",
    });
}

