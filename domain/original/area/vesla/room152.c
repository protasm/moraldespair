inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Main Road";
    long_desc = "The southern main road is rutted and split, its stones\n"
                + "tipped at odd angles.\n"
                + "A fallen signboard lies half buried in dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "south",
        "domain/original/area/vesla/room819", "west",
        "domain/original/area/vesla/room817", "east",
        "domain/original/area/vesla/room153", "north",
    });
}

