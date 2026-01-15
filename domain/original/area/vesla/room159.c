inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "The paving stones here are splintered and slick with lichen. Dust lies thick\n"
              + "against the bases of the walls.\n";
    dest_dir = ({
        "domain/original/area/vesla/room158", "south",
        "domain/original/area/vesla/room125", "north",
    });
}


