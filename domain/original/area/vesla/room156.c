inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Southern Main Road";
    long_desc = "The main road is split and collapsed, its stones scattered among ruined foundations. The silence of the dead city hangs over the broken way.\n";
    dest_dir = ({
        "domain/original/area/vesla/room155", "south",
        "domain/original/area/vesla/room822", "west",
        "domain/original/area/vesla/room424", "east",
        "domain/original/area/vesla/room157", "north",
    });
}

