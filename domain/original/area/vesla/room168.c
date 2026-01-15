inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Main Wall Crossing";
    long_desc = "The crossing is wide and empty, marked by worn paving and shallow ruts. A\n"
              + "broken curb rings the corner where the streets meet.\n";
    dest_dir = ({
        "domain/original/area/vesla/room167", "south",
        "domain/original/area/vesla/room793", "west",
        "domain/original/area/vesla/room170", "east",
        "domain/original/area/vesla/room169", "north",
    });
}

