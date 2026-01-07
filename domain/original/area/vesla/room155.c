inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Southern Main Road";
    long_desc = "The main road is split and collapsed, its stones scattered among ruined foundations. The silence of the dead city hangs over the broken way.\n";
    dest_dir = ({
        "domain/original/area/vesla/room154", "south",
        "domain/original/area/vesla/room423", "west",
        "domain/original/area/vesla/room422", "east",
        "domain/original/area/vesla/room156", "north",
    });
}

