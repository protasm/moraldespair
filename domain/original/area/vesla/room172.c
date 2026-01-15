inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "A broad road runs north and south, its surface worn into shallow\n"
              + "ruts that hold dust and rain marks. Collapsed storefronts sag\n"
              + "along the edges, their doorways open to the air.\n";
    dest_dir = ({
        "domain/original/area/vesla/room116", "south",
        "domain/original/area/vesla/room226", "west",
        "domain/original/area/vesla/room735", "east",
        "domain/original/area/vesla/room173", "north",
    });
}

