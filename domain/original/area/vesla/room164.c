inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Main Road";
    long_desc = "The road passes a doorway choked with rubble and ivy.\n"
                + "Small pools of rain-dark water stain the stones.\n";
    dest_dir = ({
        "domain/original/area/vesla/room163", "south",
        "domain/original/area/vesla/room812", "east",
        "domain/original/area/vesla/room165", "north",
    });
}

