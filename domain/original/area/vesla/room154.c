inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Southern Main Road";
    long_desc = "The main road is split and collapsed, its stones scattered among ruined foundations. The silence of the dead city hangs over the broken way.\n";
    dest_dir = ({
        "domain/original/area/vesla/room153", "south",
        "domain/original/area/vesla/room821", "east",
        "domain/original/area/vesla/room155", "north",
    });
}

