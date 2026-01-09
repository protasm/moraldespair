inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Crossing of a Stone Avenue and a Silent Street";
    long_desc = "Shattered paving and vitrified basalt mark this ruined "
        + "crossing. The bells are long silent, and ash coats the stones.\n";
    dest_dir = ({
        "domain/original/area/vesla/room141", "south",
        "domain/original/area/vesla/room204", "east",
        "domain/original/area/vesla/room139", "north",
    });
}
