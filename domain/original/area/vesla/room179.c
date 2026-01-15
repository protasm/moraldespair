inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road straightens and grows bare, its center rutted by the\n"
              + "ghost of old traffic. A broken post leans beside a gap where a\n"
              + "shopfront has collapsed.\n";
    dest_dir = ({
        "domain/original/area/vesla/room178", "south",
        "domain/original/area/vesla/room180", "north",
    });
}
