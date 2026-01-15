inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "The southern main road is rutted and split, its stones tipped at odd angles. A\n"
              + "fallen signboard lies half buried in dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "south",
        "domain/original/area/vesla/room819", "west",
        "domain/original/area/vesla/room817", "east",
        "domain/original/area/vesla/room153", "north",
    });
}


